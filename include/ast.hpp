#pragma once

#include <memory>
#include <string>
#include <vector>

namespace sql {

struct Expr {
    virtual ~Expr() = default;
};

struct ColumnRef final : Expr {
    std::string table;
    std::string column;
};

struct WildcardRef final : Expr {
    std::string table;
};

struct Literal final : Expr {
    std::string value;
};

struct FunctionCall final : Expr {
    std::string name;
    std::unique_ptr<Expr> argument;
};

struct BinaryExpr final : Expr {
    std::string op;
    std::unique_ptr<Expr> left;
    std::unique_ptr<Expr> right;
};

struct SelectItem {
    std::unique_ptr<Expr> expr;
};

struct TableRef {
    std::string name;
    std::string alias;
};

struct JoinClause {
    TableRef table;
    std::unique_ptr<Expr> condition;
};

struct OrderItem {
    std::unique_ptr<Expr> expr;
    bool descending = false;
};

struct SelectStatement {
    std::vector<SelectItem> select_items;
    TableRef from;
    std::vector<JoinClause> joins;
    std::unique_ptr<Expr> where;
    std::vector<std::unique_ptr<Expr>> group_by;
    std::vector<OrderItem> order_by;
};

using SelectStatementPtr = std::unique_ptr<SelectStatement>;

} // namespace sql
