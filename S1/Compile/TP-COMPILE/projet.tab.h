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

#ifndef YY_YY_PROJET_TAB_H_INCLUDED
# define YY_YY_PROJET_TAB_H_INCLUDED
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
    idf = 258,
    entier = 259,
    reel = 260,
    Real = 261,
    Integer = 262,
    aco = 263,
    acf = 264,
    VIR = 265,
    PVT = 266,
    Const = 267,
    CrochO = 268,
    CrochF = 269,
    eg = 270,
    ADD = 271,
    SUS = 272,
    MUL = 273,
    DIV = 274,
    pthO = 275,
    pthF = 276,
    ptpt = 277,
    afc = 278,
    INF = 279,
    SUP = 280,
    PointP = 281,
    Diaz = 282,
    TAB = 283,
    BOUCLE = 284,
    INFEG = 285,
    SUPEG = 286,
    DIFF = 287,
    OR = 288,
    AND = 289,
    NEG = 290,
    While = 291,
    Execute = 292,
    IF = 293,
    Comment = 294,
    Sep = 295,
    Calcul = 296
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 9 "projet.y" /* yacc.c:1909  */

char *nom;
int ent;


#line 102 "projet.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PROJET_TAB_H_INCLUDED  */
