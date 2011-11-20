
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TBEGIN = 258,
     TEND = 259,
     TOWN = 260,
     TREAL = 261,
     TINTEGER = 262,
     TBOOLEAN = 263,
     TARRAY = 264,
     TSWITCH = 265,
     TPROCEDURE = 266,
     TSTRING = 267,
     TLABEL = 268,
     TVALUE = 269,
     TSTEP = 270,
     TUNTIL = 271,
     TWHILE = 272,
     TCOMMENT = 273,
     TGOTO = 274,
     TIF = 275,
     TTHEN = 276,
     TELSE = 277,
     TFOR = 278,
     TDO = 279,
     TEQUIV = 280,
     TIMPL = 281,
     TOR = 282,
     TAND = 283,
     TNOT = 284,
     TLESS = 285,
     TNOTGREATER = 286,
     TEQUAL = 287,
     TNOTLESS = 288,
     TGREATER = 289,
     TNOTEQUAL = 290,
     TTRUE = 291,
     TFALSE = 292,
     TPOWER = 293,
     TANY_SYMBOL_SEQ_WO_QUOTE = 294,
     TDIGIT = 295,
     TLETTER = 296,
     TASSIGN = 297
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


