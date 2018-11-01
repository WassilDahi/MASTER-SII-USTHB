%{
	#include <stdio.h>
	#include "projet.tab.h"
	#include <stdlib.h>
	#include <string.h>
	
	extern YYSTYPE yylval;
        int l=1;
	int c=1;
%}

idf [A-Z]+([a-zA-Z0-9])*
entier [-]?[0-9]+
reel [-]?[0-9]+\.[0-9]+
blanc [ ]
tab [\t]
sl [\n]
aco "{"
acf "}"
VIR ","
PVT ";"
afc "="
ADD "+"
SUS "-"
MUL "*"
DIV "/"
pthO "("
pthF ")"
ptpt ":"
eg "=="
INF "<"
SUP ">"
INFEG "<="
SUPEG ">="
DIFF "!="
OR "|"
AND "&"
NEG "!"
IF "IF"
Comment "//"(.*\n*)*"//"
PointP "::"
Sep "||"
Diaz "#"
CrochO "["
CrochF "]"

%%
{idf} {
	if(yyleng<=12)
	{
		c = c + yyleng;
		if (strcmp(yytext,"Const")==0){c=c+5; return Const;}
		if (strcmp(yytext,"Integer")==0){c=c+7; return Integer;}	
		if (strcmp(yytext,"Real")==0) {c=c+4 ; return Real; }
		if (strcmp(yytext,"While")==0) {c=c+5 ; return While; }
		if (strcmp(yytext,"Execute")==0){c=c+7 ; return Execute;}
		if (strcmp(yytext,"IF")==0) { c=c+2 ; return IF;}
		if (strcmp(yytext,"Calcul")==0) { c=c+6 ; return Calcul;}	
		if (strcmp(yytext,"BOUCLE")==0) { c=c+6 ; return BOUCLE;}	
		if (strcmp(yytext,"TAB")==0) { c=c+2 ; return TAB;}
		else  {
	               
            	 return idf;
	}
	}
	else
	{
		printf("Erreur ligne %d colonne %d  --->  ",l,c);
		
		printf("\n");
		exit(0);
	}
      }
{entier} {
		if ( atoi(yytext) >32767)
		{
			printf("Erreur ligne %d colonne %d  --->  ",l,c);
			ECHO;
			printf("\n");
			exit(0);	
		}
		else
		{	
			c = c + 4;
			return entier;
		}
	}
{reel} {c = c + 4 ; return reel;}
{sl} {l++;c=1;}
{blanc} {c++;}
{tab} {c=c+8;}
{aco} {c++ ;return aco ;}
{acf} {c++ ;return acf ;}
{VIR} {c++; return VIR ; }
{PVT} {c++; return PVT ; }
{afc} {c++;return afc ; }
{ADD} {c++; return ADD;}
{SUS} {c++; return SUS;}
{MUL} {c++; return MUL;}
{DIV} {c++; return DIV;}
{pthO} {c++; return pthO;}
{pthF} {c++; return pthF;}
{ptpt} {c++; return ptpt;}
{eg} {c=c+2; return eg;}
{INF} {c++; return INF;}
{SUP} {c++; return SUP;}
{CrochO} {c++; return CrochO ; }
{CrochF} {c++; return CrochF ; } 
{INFEG} {c=c+2; return INFEG;}
{SUPEG} {c=c+2; return SUPEG;}
{DIFF} {c=c+2; return DIFF;}
{OR} {c++; return OR;}
{AND} {c++; return AND;}
{NEG} {c++; return NEG;}
{PointP} {c=c+2; return PointP ; }
{Sep} {c=c+2; return Sep ; }
{Diaz} {c++; return Diaz;}
{Comment} {
	FILE *f = fopen("yytext.txt","w");
	fputs(yytext,f);
	fclose(f);
	f = fopen("yytext.txt","r");
	char chaine[1000]="";
	while(fgets(chaine,1000,f) != NULL)	l++;
	fclose(f);
	l--;
	c=1;
}
. {
	printf("Erreur ligne %d colonne %d  --->  ",l,c);
	ECHO;
	printf("\n                                 ^^^\n");
	exit(0);
}
%%

int yywrap(){
	return 1;
}
