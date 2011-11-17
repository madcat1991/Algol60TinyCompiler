%{
    #include <string>
    #include "node.h"
    #include "parser.hpp"
    #define SAVE_TOKEN yylval.string = new std::string(yytext, yyleng)
    #define TOKEN(t) (yylval.token = t)
    extern "C" int yywrap() { }
%}

%%
//операторы
//арифметические
    "+"                                  return TOKEN(TPLUS);
    "-"                                   return TOKEN(TMINUS);
    "*"                                   return TOKEN(TMUL);
    "/"                                   return TOKEN(TDIV);
    "ч"                                  return TOKEN(TDIV);
    "POWER"                                  return TOKEN(TPOWER);
    
//сравненительные
    "<" | "LESS"                                 return TOKEN(TCLESS);
    "s" | "NOTGREATER"                              return TOKEN(TCNGREATER);
    ">" | "GREATER"                                 return TOKEN(TCGREATER);
    "Д" | "NOTLESS"                              return TOKEN(TCNLESS);
    "=" | "EQUAL"                                 return TOKEN(TCEQ);
    "," | "NOTEQUAL"                                return TOKEN(TCNEQ);
    
//логические
    "EQUIV"                                return TOKEN(TLEQUIV);
    "IMPL"                                return TOKEN(TLIMPL);
    "OR"                                return TOKEN(TLOR);
    "AND"                                return TOKEN(TLAND);
    "NOT"                                return TOKEN(TLNOT);

//пробельные символы    
    [ \t\n];    
    
//последовательности
    "GOTO"                                  return TOKEN(TGOTO);
    "IF"                                return TOKEN(TIF);
    "THEN"                                 return TOKEN(TTHEN);
    "ELSE"                                 return TOKEN(TELSE);
    "FOR"                                 return TOKEN(TFOR);
    "DO"                                return TOKEN(TDO);
    
//разделитель
    ","                                return TOKEN(TCOMMA);
    "."                                 return TOKEN(TDOT);
    "E";
    ":"                                 return TOKEN(TDDOT);
    ";"                                 return TOKEN(TDCOMMA);
    ":="                                 return TOKEN(TASSIGNMENT);
    "_"                                 return TOKEN(TUNDERLINE);
    "STEP"                                 return TOKEN(TSTEP);
    "UNTIL"                                 return TOKEN(TUNTIL);
    "WHILE"                                 return TOKEN(TWHILE);
    "COMMENT"                                 return TOKEN(TCOMMENT);
    
//границы
    "("                                 return TOKEN(TROPEN);
    ")"                                 return TOKEN(TRCLOSE);
    "["                                 return TOKEN(TBOPEN);
    "]"                                 return TOKEN(TBCLOSE);
    "BEGIN"                        return TOKEN(TBEGIN); 
    "END"                        return TOKEN(TEND); 
    
//деклараторы
    "OWN"                                 return TOKEN(TDOWN);
    "BOOLEAN"                                 return TOKEN(TDBOOLEAN);
    "INTEGER"                                 return TOKEN(TDINTEGER);
    "REAL"                                 return TOKEN(TDREAL);
    "ARRAY"                        return TOKEN(TDARRAY); 
    "SWITCH"                        return TOKEN(TDSWITCH); 
    
//спецификаторы
    "STRING"                                 return TOKEN(TSSTRING);
    "LABEL"                                 return TOKEN(TSLABEL);
    "VALUE"                                 return TOKEN(TSVALUE);

//логические значени€
    "TRUE"                                 return TOKEN(TTRUE);
    "FALSE"                                 return TOKEN(TFALSE);

//числа
    [0-9]               return TOKEN(TDIGIT);
    
//буква
    [a-zA-Z]            return TOKEN(TLETTER);
    
%%