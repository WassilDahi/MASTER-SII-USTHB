%{
	#include <stdio.h>
    #include <stdlib.h>
	#include <string.h>
	#include "testb.tab.h"
	
    extern YYSTYPE yylval;
    int l=1,c=0;
%}

%option nounput
%option noinput

t [ \t]
s [\n]
idf [a-z]+
entier [0-9]+
reel [0-9]+\.[0-9]*|\.[0-9]+
pvirg ";"
virg ","
accoouv "{"
accofer "}"
Integ "INT"
real "REAL"
bfor "FOR"
plus "+"
moins "-"
egal "="
parouv "(" 
parfer ")"
inf "<"
sup ">"
division "/"

%%


{idf} {c=c+yyleng;return idf;}

{entier} {
			
		if ( atoi(yytext) >32767)
		{
			printf("Erreur ligne %d colonne %d  --->  ",l,c);
			printf("\n");
			exit(0);	
		}
		else
		{	
			c = c + yyleng;
			return entier;
		}
}

{reel} {c=c+yyleng;return reel;}
{s} {l++;c=0;}
{t} {c=c+yyleng;}
{virg} {c++;return virg;}
{pvirg} {c++;return pvirg;}

{plus} {c++; return plus;}
{moins} {c++;return moins;}
{bfor} {c=c+3; return bfor;}
{inf} {c++; return inf;}
{sup} {c++; return sup;}
{division} {c++; return division;}
{parouv} {c++;return parouv;}
{parfer} {c++; return parfer;}
{real} {c=c+4;return real;}
{Integ} {c=c+3;return Integ;}
{accofer} {c++;return accofer;}
{accoouv} {c++;return accoouv;}
{egal} {c++;return egal;}

. {
	printf("Erreur ligne %d colonne %d  entite %s--->  ",l,c,yytext);
	printf("\n\n");
	exit(0);}

%%

int yywrap(){
	return 1;
}