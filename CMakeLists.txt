cmake_minimum_required(VERSION 3.16)

project(sql_parser_ast_analyzer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

BISON_TARGET(
    SqlParser
    ${CMAKE_CURRENT_SOURCE_DIR}/grammar/sql_parser.y
    ${CMAKE_CURRENT_BINARY_DIR}/sql_parser.cpp
    DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/sql_parser.hpp
)

FLEX_TARGET(
    SqlLexer
    ${CMAKE_CURRENT_SOURCE_DIR}/grammar/sql_lexer.l
    ${CMAKE_CURRENT_BINARY_DIR}/sql_lexer.cpp
)

ADD_FLEX_BISON_DEPENDENCY(SqlLexer SqlParser)

add_executable(sql_analyzer
    src/main.cpp
    src/ast.cpp
    src/semantic_analyzer.cpp
    ${BISON_SqlParser_OUTPUTS}
    ${FLEX_SqlLexer_OUTPUTS}
)

target_include_directories(sql_analyzer PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_BINARY_DIR}
)

enable_testing()

add_test(
    NAME smoke_test
    COMMAND sql_analyzer
        "SELECT u.id,u.name FROM users u WHERE u.id=10 ORDER BY u.name;"
)
