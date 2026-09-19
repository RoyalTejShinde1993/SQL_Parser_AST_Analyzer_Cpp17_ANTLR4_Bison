#include "semantic_analyzer.hpp"

#include <algorithm>

namespace sql {

namespace {

bool contains(const std::vector<std::string>& values,
              const std::string& value)
{
    return std::find(values.begin(), values.end(), value) != values.end();
}

} // namespace

SemanticAnalyzer::Schema SemanticAnalyzer::buildSchema() const
{
    return {
        {"users", {"id", "name", "email"}},
        {"orders", {"id", "user_id", "amount"}}
    };
}

bool SemanticAnalyzer::tableExists(
    const std::string& table,
    const Schema& schema) const
{
    return schema.find(table) != schema.end();
}

bool SemanticAnalyzer::columnExists(
    const std::string& table,
    const std::string& column,
    const Schema& schema) const
{
    const auto it = schema.find(table);

    if (it == schema.end()) {
        return false;
    }

    return contains(it->second, column);
}

AnalysisResult SemanticAnalyzer::analyze(
    const SelectStatement& statement) const
{
    AnalysisResult result;
    const Schema schema = buildSchema();

    if (statement.from.name.empty()) {
        result.valid = false;
        result.errors.push_back("Missing FROM table.");
        return result;
    }

    if (!tableExists(statement.from.name, schema)) {
        result.valid = false;
        result.errors.push_back(
            "Unknown table: " + statement.from.name);
    }

    addTable(result.tables, statement.from.name);

    for (const auto& join : statement.joins) {
        if (!tableExists(join.table.name, schema)) {
            result.valid = false;
            result.errors.push_back(
                "Unknown table: " + join.table.name);
        }

        addTable(result.tables, join.table.name);

        analyzeExpr(
            join.condition.get(),
            statement,
            schema,
            result);
    }

    for (const auto& item : statement.select_items) {
        analyzeExpr(
            item.expr.get(),
            statement,
            schema,
            result);
    }

    analyzeExpr(
        statement.where.get(),
        statement,
        schema,
        result);

    analyzeExpr(
        statement.having.get(),
        statement,
        schema,
        result);

    for (const auto& expr : statement.group_by) {
        analyzeExpr(
            expr.get(),
            statement,
            schema,
            result);
    }

    for (const auto& item : statement.order_by) {
        analyzeExpr(
            item.expr.get(),
            statement,
            schema,
            result);
    }

    validateGroupBy(statement, result);

    return result;
}

void SemanticAnalyzer::analyzeExpr(
    const Expr* expr,
    const SelectStatement& statement,
    const Schema& schema,
    AnalysisResult& result) const
{
    if (!expr) {
        return;
    }

    if (const auto* wildcard =
        dynamic_cast<const WildcardRef*>(expr)) {

    if (wildcard->table.empty()) {
        return;
    }

    bool knownTable =
        wildcard->table == statement.from.name ||
        wildcard->table == statement.from.alias;

    if (!knownTable) {
        for (const auto& join : statement.joins) {
            if (wildcard->table == join.table.name ||
                wildcard->table == join.table.alias) {
                knownTable = true;
                break;
            }
        }
    }

    if (!knownTable) {
        result.valid = false;
        result.errors.push_back(
            "Unknown table or alias: " + wildcard->table);
    }

    return;
}

    if (const auto* column = dynamic_cast<const ColumnRef*>(expr)) {
        if (!column->table.empty()) {
            bool knownTable = false;
            std::string actualTable;

            if (column->table == statement.from.name ||
                column->table == statement.from.alias) {
                knownTable = true;
                actualTable = statement.from.name;
            }

            if (!knownTable) {
                for (const auto& join : statement.joins) {
                    if (column->table == join.table.name ||
                        column->table == join.table.alias) {
                        knownTable = true;
                        actualTable = join.table.name;
                        break;
                    }
                }
            }

            if (!knownTable) {
                result.valid = false;
                result.errors.push_back(
                    "Unknown table or alias: " + column->table);
            } else if (!columnExists(
                           actualTable,
                           column->column,
                           schema)) {
                result.valid = false;
                result.errors.push_back(
                    "Unknown column: " +
                    column->table + "." + column->column);
            }
        } else {
            int matches = 0;

            if (columnExists(
                    statement.from.name,
                    column->column,
                    schema)) {
                ++matches;
            }

            for (const auto& join : statement.joins) {
                if (columnExists(
                        join.table.name,
                        column->column,
                        schema)) {
                    ++matches;
                }
            }

            if (matches == 0) {
                result.valid = false;
                result.errors.push_back(
                    "Unknown column: " + column->column);
            } else if (matches > 1) {
                result.valid = false;
                result.errors.push_back(
                    "Ambiguous column: " + column->column);
            }
        }

        addColumn(result.columns, column->column);
        return;
    }

    if (const auto* binary = dynamic_cast<const BinaryExpr*>(expr)) {
        analyzeExpr(
            binary->left.get(),
            statement,
            schema,
            result);

        analyzeExpr(
            binary->right.get(),
            statement,
            schema,
            result);

        return;
    }

    if (const auto* arithmetic =
        dynamic_cast<const ArithmeticExpr*>(expr)) {

    analyzeExpr(
        arithmetic->left.get(),
        statement,
        schema,
        result);

    analyzeExpr(
        arithmetic->right.get(),
        statement,
        schema,
        result);

    return;
    }

    if (const auto* null_check =
        dynamic_cast<const NullCheckExpr*>(expr)) {

    analyzeExpr(
        null_check->expression.get(),
        statement,
        schema,
        result);

    return;
    }

    if (const auto* in_expr =
        dynamic_cast<const InExpr*>(expr)) {

    analyzeExpr(
        in_expr->expression.get(),
        statement,
        schema,
        result);

    for (const auto& value : in_expr->values) {
        analyzeExpr(
            value.get(),
            statement,
            schema,
            result);
    }

    return;
    }

    if (const auto* function =
    dynamic_cast<const FunctionCall*>(expr)) {

    analyzeExpr(
        function->argument.get(),
        statement,
        schema,
        result);

    return;
}
if (dynamic_cast<const Literal*>(expr)) {
return;
}

result.valid = false;
result.errors.push_back("Unknown expression node.");
}

bool SemanticAnalyzer::isAggregateFunction(
    const Expr* expr) const
{
    const auto* function =
        dynamic_cast<const FunctionCall*>(expr);

    if (!function) {
        return false;
    }

    return function->name == "COUNT" ||
           function->name == "count" ||
           function->name == "SUM" ||
           function->name == "sum" ||
           function->name == "AVG" ||
           function->name == "avg" ||
           function->name == "MIN" ||
           function->name == "min" ||
           function->name == "MAX" ||
           function->name == "max";
}

bool SemanticAnalyzer::isGroupedExpression(
    const Expr* expr,
    const SelectStatement& statement) const
{
    const auto* column =
        dynamic_cast<const ColumnRef*>(expr);

    if (!column) {
        return false;
    }

    for (const auto& group_expr : statement.group_by) {
        const auto* grouped_column =
            dynamic_cast<const ColumnRef*>(group_expr.get());

        if (!grouped_column) {
            continue;
        }

        if (column->column != grouped_column->column) {
            continue;
        }

        if (column->table == grouped_column->table) {
            return true;
        }

        if (column->table.empty() &&
            grouped_column->table.empty()) {
            return true;
        }

        if (column->table.empty() ||
            grouped_column->table.empty()) {
            continue;
        }

        if (column->table == statement.from.name &&
            grouped_column->table == statement.from.alias) {
            return true;
        }

        if (column->table == statement.from.alias &&
            grouped_column->table == statement.from.name) {
            return true;
        }
    }

    return false;
}

void SemanticAnalyzer::validateGroupBy(
    const SelectStatement& statement,
    AnalysisResult& result) const
{
    if (statement.group_by.empty()) {
        return;
    }

    for (const auto& item : statement.select_items) {
        const Expr* expr = item.expr.get();

        if (isAggregateFunction(expr)) {
            continue;
        }

        const auto* column =
            dynamic_cast<const ColumnRef*>(expr);

        if (!column) {
            continue;
        }

        if (!isGroupedExpression(expr, statement)) {
            result.valid = false;
            result.errors.push_back(
                "Column '" + column->column +
                "' must appear in GROUP BY or be used in an aggregate function.");
        }
    }
}

void SemanticAnalyzer::addTable(
    std::vector<std::string>& tables,
    const std::string& table) const
{
    if (!table.empty() && !contains(tables, table)) {
        tables.push_back(table);
    }
}

void SemanticAnalyzer::addColumn(
    std::vector<std::string>& columns,
    const std::string& column) const
{
    if (!column.empty() && !contains(columns, column)) {
        columns.push_back(column);
    }
}

} // namespace sql
