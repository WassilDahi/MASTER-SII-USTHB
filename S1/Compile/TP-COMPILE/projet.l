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
Integer "Integer"
Real "Real"
While "While"
Execute "Execute"
IF "IF"
Comment "//"(.*\n*)*"//"
PointP "::"
Sep "||"
Diaz "#"

%%
{idf} {
	if(yyleng<=12)
	{
		c = c + 4;
		if (strcmp(yytext,"Const")==0) return Const;
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
{Integer} {c=c+7; return Integer;}
{Real} {c=c+4; return Real;}
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
{INFEG} {c=c+2; return INFEG;}
{SUPEG} {c=c+2; return SUPEG;}
{DIFF} {c=c+2; return DIFF;}
{OR} {c++; return OR;}
{AND} {c++; return AND;}
{NEG} {c++; return NEG;}
{While} { c=c+5 ; return While ; }
{Execute} {c=c+7 ; return Execute; }
{IF} { c=c+2 ; return IF ; }
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
