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
    INNER = 268,                   /* INNER  */
    LEFT = 269,                    /* LEFT  */
    RIGHT = 270,                   /* RIGHT  */
    FULL = 271,                    /* FULL  */
    CROSS = 272,                   /* CROSS  */
    ON = 273,                      /* ON  */
    ORDER = 274,                   /* ORDER  */
    GROUP = 275,                   /* GROUP  */
    BY = 276,                      /* BY  */
    HAVING = 277,                  /* HAVING  */
    AS = 278,                      /* AS  */
    AND = 279,                     /* AND  */
    OR = 280,                      /* OR  */
    IS = 281,                      /* IS  */
    NOT = 282,                     /* NOT  */
    NULL_TOKEN = 283,              /* NULL_TOKEN  */
    IN = 284,                      /* IN  */
    ASC = 285,                     /* ASC  */
    DESC = 286,                    /* DESC  */
    EQ = 287,                      /* EQ  */
    GT = 288,                      /* GT  */
    LT = 289,                      /* LT  */
    GTE = 290,                     /* GTE  */
    LTE = 291,                     /* LTE  */
    NEQ = 292,                     /* NEQ  */
    PLUS = 293,                    /* PLUS  */
    MINUS = 294,                   /* MINUS  */
    STAR = 295,                    /* STAR  */
    SLASH = 296,                   /* SLASH  */
    COMMA = 297,                   /* COMMA  */
    DOT = 298,                     /* DOT  */
    SEMICOLON = 299,               /* SEMICOLON  */
    IDENT = 300,                   /* IDENT  */
    NUMBER = 301,                  /* NUMBER  */
    STRING = 302                   /* STRING  */
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

#line 132 "sql_parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SQL_PARSER_TAB_H_INCLUDED  */
