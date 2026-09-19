%{
#include "sql_parser.hpp"
#include <string>
%}

%%

[ \t\r\n]+              ;

"SELECT"|"select"       return SELECT;
"DISTINCT"|"distinct"   return DISTINCT;
"COUNT"|"count"         return COUNT;
"SUM"|"sum"             return SUM;
"AVG"|"avg"             return AVG;
"FROM"|"from"           return FROM;
"WHERE"|"where"         return WHERE;
"JOIN"|"join"           return JOIN;
"ON"|"on"               return ON;
"ORDER"|"order"         return ORDER;
"GROUP"|"group"         return GROUP;
"BY"|"by"               return BY;
"HAVING"|"having"       return HAVING;
"AS"|"as"               return AS;
"AND"|"and"             return AND;
"OR"|"or"               return OR;
"IS"|"is"               return IS;
"NOT"|"not"             return NOT;
"IN"|"in"               return IN;
"NULL"|"null"           return NULL_TOKEN;
"ASC"|"asc"             return ASC;
"DESC"|"desc"           return DESC;
"MIN"|"min"             return MIN;
"MAX"|"max"             return MAX;

">="                    return GTE;
"<="                    return LTE;
"!="                    return NEQ;
"="                     return EQ;
">"                     return GT;
"<"                     return LT;

","                     return COMMA;
"."                     return DOT;
";"                     return SEMICOLON;
"+"                     return PLUS;
"-"                     return MINUS;
"*"                     return STAR;
"/"                     return SLASH;

[0-9]+                  {
                            yylval.str = new std::string(yytext);
                            return NUMBER;
                        }

"'"[^']*"'"             {
                            yylval.str = new std::string(yytext);
                            return STRING;
                        }

[A-Za-z_][A-Za-z0-9_]*  {
                            yylval.str = new std::string(yytext);
                            return IDENT;
                        }

.                       {
                            return yytext[0];
                        }

%%

int yywrap(void)
{
    return 1;
}
