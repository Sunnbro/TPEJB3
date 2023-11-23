
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
     dt_div = 258,
     pr_div = 259,
     IF = 260,
     ELSE = 261,
     FOR = 262,
     STRUCT = 263,
     WHILE = 264,
     idf = 265,
     integer = 266,
     flt = 267,
     minus = 268,
     plus = 269,
     times = 270,
     divise = 271,
     G = 272,
     L = 273,
     EQ = 274,
     GE = 275,
     LE = 276,
     DI = 277,
     egl = 278,
     and = 279,
     or = 280,
     not = 281,
     INTEGER = 282,
     FLOAT = 283,
     CONST = 284,
     point = 285,
     vrg = 286,
     pvg = 287,
     Dpoints = 288,
     Pouvr = 289,
     Pferm = 290,
     accol = 291,
     accor = 292,
     baro = 293,
     barf = 294
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 13 "S.y"

         int rxtype;
         char* str;
         struct{
                char* vlr; 
                char* type;
           }Strutype;



/* Line 1676 of yacc.c  */
#line 102 "S.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


