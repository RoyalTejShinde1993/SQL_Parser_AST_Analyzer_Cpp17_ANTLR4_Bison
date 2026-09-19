#pragma once

#include "ast.hpp"

#include <string>
#include <unordered_map>
#include <vector>

namespace sql {

struct AnalysisResult {
    bool valid = true;
    std::vector<std::string> errors;
    std::vector<std::string> tables;
    std::vector<std::string> columns;
};

class SemanticAnalyzer {
public:
    AnalysisResult analyze(const SelectStatement& statement) const;

private:
    using Schema = std::unordered_map<
        std::string,
        std::vector<std::string>
    >;

    Schema buildSchema() const;

    bool tableExists(
        const std::string& table,
        const Schema& schema) const;

    bool columnExists(
        const std::string& table,
        const std::string& column,
        const Schema& schema) const;

    void analyzeExpr(
        const Expr* expr,
        const SelectStatement& statement,
        const Schema& schema,
        AnalysisResult& result) const;


    bool isAggregateFunction(
        const Expr* expr) const;

    bool isGroupedExpression(
        const Expr* expr,
        const SelectStatement& statement) const;

    void validateGroupBy(
        const SelectStatement& statement,
        AnalysisResult& result) const;

    void addTable(
        std::vector<std::string>& tables,
        const std::string& table) const;

    void addColumn(
        std::vector<std::string>& columns,
        const std::string& column) const;
};

} // namespace sql
