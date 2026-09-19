#include "ast.hpp"
#include "semantic_analyzer.hpp"

#include <iostream>
#include <memory>
#include <string>


extern int yyparse();
extern int yylex_destroy();

std::unique_ptr<sql::SelectStatement> parsed_statement;

extern void yy_scan_string(const char*);


int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cerr << "Usage: sql_analyzer \"SQL_STATEMENT\"\n";
        return 1;
    }

    const std::string sql = argv[1];

    std::cout << "SQL: " << sql << "\n\n";

    std::cout << "Parser pipeline:\n";
    std::cout << "  SQL -> Lexer -> Bison Parser -> AST -> Semantic Analysis\n\n";

    parsed_statement.reset();

    yy_scan_string(sql.c_str());

    const int parse_result = yyparse();

    yylex_destroy();

    if (parse_result != 0 || !parsed_statement) {
        std::cerr << "Parse failed.\n";
        return 2;
    }

    std::cout << "Syntax: valid\n";

    std::cout << "Distinct: "
              << (parsed_statement->distinct ? "yes" : "no")
              << "\n";

    const sql::SemanticAnalyzer analyzer;

    const sql::AnalysisResult result =
        analyzer.analyze(*parsed_statement);

    std::cout << "Semantic analysis: "
              << (result.valid ? "valid" : "invalid")
              << "\n\n";

    std::cout << "Tables:\n";
    for (const auto& table : result.tables) {
        std::cout << "  - " << table << "\n";
    }

    std::cout << "\nSelect items:\n";
    for (const auto& item : parsed_statement->select_items) {
        std::cout << "  - ";

        if (!item.alias.empty()) {
            std::cout << item.alias;
        } else {
            std::cout << "(no alias)";
        }

        std::cout << "\n";
    }

    std::cout << "\nColumns:\n";
    for (const auto& column : result.columns) {
        std::cout << "  - " << column << "\n";
    }

    if (!result.errors.empty()) {
        std::cout << "\nErrors:\n";

        for (const auto& error : result.errors) {
            std::cout << "  - " << error << "\n";
        }
    }

    return result.valid ? 0 : 3;
}