/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INUM = 258,
    RNUM = 259,
    PROGRAM = 260,
    ID = 261,
    VAR = 262,
    BBEGIN = 263,
    END = 264,
    PROCEDURE = 265,
    FUNCTION = 266,
    DOTS = 267,
    ARRAY = 268,
    OF = 269,
    INTEGER = 270,
    REAL = 271,
    RELOP = 272,
    EQ = 273,
    NE = 274,
    LT = 275,
    LE = 276,
    GT = 277,
    GE = 278,
    ASSIGNOP = 279,
    ADDOP = 280,
    PLUS = 281,
    MINUS = 282,
    OR = 283,
    MULOP = 284,
    STAR = 285,
    SLASH = 286,
    AND = 287,
    NOT = 288,
    IF = 289,
    THEN = 290,
    ELSE = 291,
    WHILE = 292,
    FOR = 293,
    DO = 294
  };
#endif
/* Tokens.  */
#define INUM 258
#define RNUM 259
#define PROGRAM 260
#define ID 261
#define VAR 262
#define BBEGIN 263
#define END 264
#define PROCEDURE 265
#define FUNCTION 266
#define DOTS 267
#define ARRAY 268
#define OF 269
#define INTEGER 270
#define REAL 271
#define RELOP 272
#define EQ 273
#define NE 274
#define LT 275
#define LE 276
#define GT 277
#define GE 278
#define ASSIGNOP 279
#define ADDOP 280
#define PLUS 281
#define MINUS 282
#define OR 283
#define MULOP 284
#define STAR 285
#define SLASH 286
#define AND 287
#define NOT 288
#define IF 289
#define THEN 290
#define ELSE 291
#define WHILE 292
#define FOR 293
#define DO 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 16 "pc.y" /* yacc.c:1909  */

    int ival; //NUM
    double dval; //REAL
    int opval; //RELOP ADDOP MULOP
    char* sval; //ID
    tree* tval;

#line 140 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
