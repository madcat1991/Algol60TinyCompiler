%{
#include "Simple.tab.h" /* The tokens */
%}
DIGIT   [0-9]
LETTER  [a-zA-Z]
ANY_SYMBOL_SEQ_WO_QUOTE [^\"]*
%%
":="    {return(TASSIGN);}
BEGIN   {return(TBEGIN);} 
END     {return(TEND);}
OWN     {return(TOWN);}
REAL    {return(TREAL);}
INTEGER {return(TINTEGER);}
BOOLEAN {return(TBOOLEAN);}
ARRAY   {return(TARRAY);}
SWITCH  {return(TSWITCH);}
PROCEDURE   {return(TPROCEDURE);}
STRING  {return(TSTRING);}
LABEL   {return(TLABEL);}
VALUE   {return(TVALUE);}
STEP    {return(TSTEP);}
UNTIL   {return(UNTIL);}
WHILE   {return(TWHILE);}
COMMENT {return(TCOMMENT);}
GOTO    {return(TGOTO);}
IF      {return(TIF);}
THEN    {return(TTHEN);}
ELSE    {return(TELSE);}
FOR     {return(TFOR);}
DO      {return(TDO);} 
EQUIV   {return(TEQUIV);}
IMPL    {return(TIMPL);}
OR      {return(TOR);}
AND     {return(TAND);}
NOT     {return(TNOT);}
LESS    {return(TLESS);}
"<="|NOTGREATER  {return(TNOTGREATER);}
EQUAL   {return(TEQUAL);}
">="|NOTLESS {return(TNOTLESS);} 
GREATER {return(GREATER);}
"!="|NOTEQUAL    {return(TNOTEQUAL);}
TRUE    {return(TTRUE);} 
FALSE   {return(TFALSE);}
POWER   {return(POWER);} 
[ \t\n]+
.       {return(yytext[0]);}
%%
