/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SQL_PARSER_TAB_H_INCLUDED
# define YY_YY_SQL_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 13 "grammar/sql_parser.y"

#include <string>
#include <vector>
#include "ast.hpp"

#line 55 "sql_parser.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    SELECT = 258,                  /* SELECT  */
    DISTINCT = 259,                /* DISTINCT  */
    COUNT = 260,                   /* COUNT  */
    SUM = 261,                     /* SUM  */
    AVG = 262,                     /* AVG  */
    MIN = 263,                     /* MIN  */
    MAX = 264,                     /* MAX  */
    FROM = 265,                    /* FROM  */
    WHERE = 266,                   /* WHERE  */
    JOIN = 267,                    /* JOIN  */
    ON = 268,                      /* ON  */
    ORDER = 269,                   /* ORDER  */
    GROUP = 270,                   /* GROUP  */
    BY = 271,                      /* BY  */
    HAVING = 272,                  /* HAVING  */
    AS = 273,                      /* AS  */
    AND = 274,                     /* AND  */
    OR = 275,                      /* OR  */
    IS = 276,                      /* IS  */
    NOT = 277,                     /* NOT  */
    NULL_TOKEN = 278,              /* NULL_TOKEN  */
    IN = 279,                      /* IN  */
    ASC = 280,                     /* ASC  */
    DESC = 281,                    /* DESC  */
    EQ = 282,                      /* EQ  */
    GT = 283,                      /* GT  */
    LT = 284,                      /* LT  */
    GTE = 285,                     /* GTE  */
    LTE = 286,                     /* LTE  */
    NEQ = 287,                     /* NEQ  */
    PLUS = 288,                    /* PLUS  */
    MINUS = 289,                   /* MINUS  */
    STAR = 290,                    /* STAR  */
    SLASH = 291,                   /* SLASH  */
    COMMA = 292,                   /* COMMA  */
    DOT = 293,                     /* DOT  */
    SEMICOLON = 294,               /* SEMICOLON  */
    IDENT = 295,                   /* IDENT  */
    NUMBER = 296,                  /* NUMBER  */
    STRING = 297                   /* STRING  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "grammar/sql_parser.y"

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

#line 127 "sql_parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SQL_PARSER_TAB_H_INCLUDED  */
