%{
    #include <string.h>
   
    #include <stdlib.h>
   
	
    int l=1,c=0;
%}

t [ \t]
S [\n]
idf [a-z]+
entier [0-9]+
reel [0-9]+\.[0-9]*|\.[0-9]+
pvirg ";"
virg ","
accoouv "{"
accofer "}"
int "INT"
real "REAL"
for "FOR"
plus "+"
moins "-"
egal "="
parouv "(" 
parfer ")"
inf "<"
sup ">"
div "/"

%%


{idf} { printf("caca");
      }

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

{reel} {c=c+yyleng;return reel;}
{S} {l++;c=0;}
{t} {c=c+yyleng;}
{virg} {c++;return virg;}
{pvirg} {c++;return pvirg;}
{plus} {c++;return plus;}
{moins} {c++;return moins;}
{for} {c=c+3; return for;}
{inf} {c++; return inf;}
{sup} {c++; return sup;}
{div} {c++; return div;}
{parouv} {c++;return parouv;}
{parfer} {c++; return parfer;}
{real} {c=c+4;return real;}
{int} {c=c+3;return int;}
{accofer} {c++;return accofer;}
{accoouv} {c++;return accoouv;}
{egal} {c++;return egal;}

. {printf("Erreur ligne %d colonne %d  entite %s--->  ",l,c,yytext);printf("\n\n");}

%%


    int