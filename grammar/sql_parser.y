%{
#include <memory>
#include <string>
#include <vector>
#include "ast.hpp"

void yyerror(const char* s);
int yylex(void);

extern std::unique_ptr<sql::SelectStatement> parsed_statement;
%}

%code requires {
#include <string>
#include <vector>
#include "ast.hpp"
}

%union {
    std::string* str;
    bool boolean;
    sql::Expr* expr;
    sql::SelectStatement* stmt;
    sql::TableRef* table;
    std::vector<sql::SelectItem>* items;
    std::vector<sql::JoinClause>* joins;
    std::vector<sql::OrderItem>* orders;
    std::vector<sql::Expr*>* group_exprs;
    std::vector<sql::Expr*>* expr_list;
}

%token SELECT DISTINCT COUNT SUM AVG MIN MAX FROM WHERE JOIN ON ORDER GROUP BY HAVING AS AND OR IS NOT NULL_TOKEN IN ASC DESC
%token EQ GT LT GTE LTE NEQ PLUS MINUS STAR SLASH COMMA DOT SEMICOLON
%left OR
%left AND
%left EQ GT LT GTE LTE NEQ
%left IS IN
%left PLUS MINUS
%left STAR SLASH
%right NOT

%token <str> IDENT NUMBER STRING

%type <stmt> statement
%type <boolean> distinct_opt
%type <items> select_list
%type <expr> expr where_opt having_opt
%type <str> select_alias_opt
%type <table> table_ref
%type <joins> join_list
%type <orders> order_opt order_list
%type <group_exprs> group_opt group_list
%type <expr_list> in_list

%%

statement:
    SELECT distinct_opt select_list FROM table_ref join_list where_opt group_opt having_opt order_opt SEMICOLON
    {
    auto stmt = new sql::SelectStatement();

    stmt->distinct = $2;
    stmt->select_items = std::move(*$3);
    stmt->from = std::move(*$5);
    stmt->joins = std::move(*$6);
    stmt->where = std::unique_ptr<sql::Expr>($7);

    for (auto* expr : *$8) {
        stmt->group_by.emplace_back(expr);
    }

    stmt->having = std::unique_ptr<sql::Expr>($9);
    stmt->order_by = std::move(*$10);

    delete $3;
    delete $5;
    delete $6;
    delete $8;
    delete $10;

    parsed_statement.reset(stmt);
    $$ = stmt;
    }
    ;
distinct_opt:
    /* empty */
    {
        $$ = false;
    }
    |
    DISTINCT
    {
        $$ = true;
    }
    ;

select_list:
    expr select_alias_opt
    {
        auto items = new std::vector<sql::SelectItem>();
        items->emplace_back();
        items->back().expr.reset($1);

        if ($2) {
            items->back().alias = *$2;
            delete $2;
        }

        $$ = items;
    }
    |
    select_list COMMA expr select_alias_opt
    {
        $1->emplace_back();
        $1->back().expr.reset($3);

        if ($4) {
            $1->back().alias = *$4;
            delete $4;
        }

        $$ = $1;
    }
    ;

table_ref:
    IDENT
    {
        auto table = new sql::TableRef();
        table->name = *$1;
        delete $1;
        $$ = table;
    }
    |
    IDENT IDENT
    {
        auto table = new sql::TableRef();
        table->name = *$1;
        table->alias = *$2;
        delete $1;
        delete $2;
        $$ = table;
    }
    |
    IDENT AS IDENT
    {
        auto table = new sql::TableRef();
        table->name = *$1;
        table->alias = *$3;
        delete $1;
        delete $3;
        $$ = table;
    }
    ;

join_list:
    /* empty */
    {
        $$ = new std::vector<sql::JoinClause>();
    }
    |
    join_list JOIN table_ref ON expr
    {
        sql::JoinClause join;
        join.table = std::move(*$3);
        join.condition.reset($5);

        $1->push_back(std::move(join));

        delete $3;
        $$ = $1;
    }
    ;

where_opt:
    /* empty */
    {
        $$ = nullptr;
    }
    |
    WHERE expr
    {
        $$ = $2;
    }
    ;
having_opt:
    /* empty */
    {
        $$ = nullptr;
    }
    |
    HAVING expr
    {
        $$ = $2;
    }
    ;
group_opt:
    /* empty */
    {
        $$ = new std::vector<sql::Expr*>();
    }
    |
    GROUP BY group_list
    {
        $$ = $3;
    }
    ;

group_list:
    expr
    {
        auto groups = new std::vector<sql::Expr*>();
        groups->push_back($1);
        $$ = groups;
    }
    |
    group_list COMMA expr
    {
        $1->push_back($3);
        $$ = $1;
    }
    ;

in_list:
    expr
    {
        auto values = new std::vector<sql::Expr*>();
        values->push_back($1);
        $$ = values;
    }
    |
    in_list COMMA expr
    {
        $1->push_back($3);
        $$ = $1;
    }
    ;

order_opt:
    /* empty */
    {
        $$ = new std::vector<sql::OrderItem>();
    }
    |
    ORDER BY order_list
    {
        $$ = $3;
    }
    ;

order_list:
    expr
    {
        auto orders = new std::vector<sql::OrderItem>();
        orders->emplace_back();
        orders->back().expr.reset($1);
        $$ = orders;
    }
    |
    expr ASC
    {
        auto orders = new std::vector<sql::OrderItem>();
        orders->emplace_back();
        orders->back().expr.reset($1);
        orders->back().descending = false;
        $$ = orders;
    }
    |
    expr DESC
    {
        auto orders = new std::vector<sql::OrderItem>();
        orders->emplace_back();
        orders->back().expr.reset($1);
        orders->back().descending = true;
        $$ = orders;
    }
    |
    order_list COMMA expr
    {
        $1->emplace_back();
        $1->back().expr.reset($3);
        $$ = $1;
    }
    |
    order_list COMMA expr ASC
    {
        $1->emplace_back();
        $1->back().expr.reset($3);
        $1->back().descending = false;
        $$ = $1;
    }
    |
    order_list COMMA expr DESC
    {
        $1->emplace_back();
        $1->back().expr.reset($3);
        $1->back().descending = true;
        $$ = $1;
    }
    ;

select_alias_opt:
    /* empty */
    {
        $$ = nullptr;
    }
    |
    AS IDENT
    {
        $$ = $2;
    }
    ;

expr:
    COUNT '(' expr ')'
    {
        auto expr = new sql::FunctionCall();
        expr->name = "COUNT";
        expr->argument.reset($3);
        $$ = expr;
    }
    |
    SUM '(' expr ')'
    {
        auto expr = new sql::FunctionCall();
        expr->name = "SUM";
        expr->argument.reset($3);
        $$ = expr;
    }
    |
    AVG '(' expr ')'
    {
        auto expr = new sql::FunctionCall();
        expr->name = "AVG";
        expr->argument.reset($3);
        $$ = expr;
    }
     |
    MIN '(' expr ')'
    {
        auto expr = new sql::FunctionCall();
        expr->name = "MIN";
        expr->argument.reset($3);
        $$ = expr;
    }
    |
    MAX '(' expr ')'
    {
        auto expr = new sql::FunctionCall();
        expr->name = "MAX";
        expr->argument.reset($3);
        $$ = expr;
    }
    |
    '(' expr ')'
    {
        $$ = $2;
    }
    |
    expr IS NULL_TOKEN
    {
        auto expr = new sql::NullCheckExpr();
        expr->expression.reset($1);
        expr->is_not = false;
        $$ = expr;
    }
    |
    expr IS NOT NULL_TOKEN
    {
        auto expr = new sql::NullCheckExpr();
        expr->expression.reset($1);
        expr->is_not = true;
        $$ = expr;
    }
    |
    expr IN '(' in_list ')'
    {
        auto expr = new sql::InExpr();
        expr->expression.reset($1);

        for (auto* value : *$4) {
            expr->values.emplace_back(value);
        }

        delete $4;

        expr->is_not = false;
        $$ = expr;
    }
    |
    expr NOT IN '(' in_list ')'
    {
        auto expr = new sql::InExpr();
        expr->expression.reset($1);

        for (auto* value : *$5) {
            expr->values.emplace_back(value);
        }

        delete $5;

        expr->is_not = true;
        $$ = expr;
    }
    |
    IDENT
    {
        auto expr = new sql::ColumnRef();
        expr->column = *$1;
        delete $1;
        $$ = expr;
    }
    |
    IDENT DOT IDENT
    {
        auto expr = new sql::ColumnRef();
        expr->table = *$1;
        expr->column = *$3;
        delete $1;
        delete $3;
        $$ = expr;
    }
    |
    STAR
    {
        $$ = new sql::WildcardRef();
    }
    |
    IDENT DOT STAR
    {
        auto expr = new sql::WildcardRef();
        expr->table = *$1;
        delete $1;
        $$ = expr;
    }
    |
    NUMBER
    {
        auto expr = new sql::Literal();
        expr->value = *$1;
        delete $1;
        $$ = expr;
    }
    |
    STRING
    {
        auto expr = new sql::Literal();
        expr->value = *$1;
        delete $1;
        $$ = expr;
    }
       |
    expr PLUS expr
    {
        auto expr = new sql::ArithmeticExpr();
        expr->op = "+";
        expr->left.reset($1);
        expr->right.reset($3);
        $$ = expr;
    }
    |
    expr MINUS expr
    {
        auto expr = new sql::ArithmeticExpr();
        expr->op = "-";
        expr->left.reset($1);
        expr->right.reset($3);
        $$ = expr;
    }
    |
    expr STAR expr
    {
        auto expr = new sql::ArithmeticExpr();
        expr->op = "*";
        expr->left.reset($1);
        expr->right.reset($3);
        $$ = expr;
    }
    |
    expr SLASH expr
    {
        auto expr = new sql::ArithmeticExpr();
        expr->op = "/";
        expr->left.reset($1);
        expr->right.reset($3);
        $$ = expr;
    }
    |
    expr EQ expr
    {
        auto expr = new sql::BinaryExpr();
        expr->op = "=";
        expr->left.reset($1);
        expr->right.reset($3);
        $$ = expr;
    }
    |
    expr GT expr
    {
        auto expr = new sql::BinaryExpr();
        expr->op = ">";
        expr->left.reset($1);
        expr->right.reset($3);
        $$ = expr;
    }
    |
    expr LT expr
    {
        auto expr = new sql::BinaryExpr();
        expr->op = "<";
        expr->left.reset($1);
        expr->right.reset($3);
        $$ = expr;
    }
    |
    expr GTE expr
    {
        auto expr = new sql::BinaryExpr();
        expr->op = ">=";
        expr->left.reset($1);
        expr->right.reset($3);
        $$ = expr;
    }
    |
    expr LTE expr
    {
        auto expr = new sql::BinaryExpr();
        expr->op = "<=";
        expr->left.reset($1);
        expr->right.reset($3);
        $$ = expr;
    }
    |
    expr NEQ expr
    {
        auto expr = new sql::BinaryExpr();
        expr->op = "!=";
        expr->left.reset($1);
        expr->right.reset($3);
        $$ = expr;
    }
    |
    expr AND expr
    {
        auto expr = new sql::BinaryExpr();
        expr->op = "AND";
        expr->left.reset($1);
        expr->right.reset($3);
        $$ = expr;
    }
    |
    expr OR expr
    {
        auto expr = new sql::BinaryExpr();
        expr->op = "OR";
        expr->left.reset($1);
        expr->right.reset($3);
        $$ = expr;
    }
    ;

%%

void yyerror(const char* s)
{
    (void)s;
}
