%{
	#include <stdio.h>
	extern FILE *yyin;
	extern int l,c;
	
	

%}
%union{
char *nom;
int ent;

}


%token idf entier reel Real Integer aco acf  VIR PVT Const
%token eg ADD SUS MUL DIV pthO pthF ptpt afc INF SUP PointP Diaz
%token INFEG SUPEG DIFF OR AND NEG While Execute IF Comment Sep
%type <nom> idf
 
%%
	S: Diaz aco idf ;
	
%%

int yyerror(char *msg)
{
	printf(" erreur syntaxique ");
	//exit(0);
return 0 ;
}

int main()
{
	yyin=fopen("input.txt","r");
	yyparse();
	
	return 1;
}
