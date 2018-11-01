%{
	#include <stdio.h>
	extern FILE *yyin;
	extern int l,c;
	
	

%}
%union{
char *nom;
int ent;

}


%token idf entier reel Real Integer aco acf  VIR PVT Const CrochO CrochF
%token eg ADD SUS MUL DIV pthO pthF ptpt afc INF SUP PointP Diaz TAB BOUCLE
%token INFEG SUPEG DIFF OR AND NEG While Execute IF Comment Sep Calcul
%type <nom> idf
 
%%
	A:Diaz Calcul A| Diaz BOUCLE A| Diaz TAB A | Diaz S ;
	S:  idf aco  D  acf ;
	

	D: Type PointP idf Var  |Type PointP Const idf afc Valeur CST 
		|Type PointP idf CrochO entier CrochF FinD ;
	CST:   FinD| VIR idf afc Valeur  CST ;
	Valeur: entier | reel ;
	Type: Integer  | Real  ;
	Var: VIR idf Var | FinD ;
	FinD:PVT D |PVT I ;
	
	I: Affect PVT I  | Boucle I|Condition I | ;

	Affect: idf afc Exp | idf CrochO entier CrochF afc Exp;
	Exp: Val OP1 | Val ;
	OP1: ADD Exp | SUS Exp | OP2 ;
	OP2: MUL Exp | DIV Exp ;
	Val: entier | reel | idf ;

	Boucle: While pthO Cond ;
	Cond:Val Expression Val pthF aco I acf ;
	Expression: INFEG | SUPEG | DIFF | eg | INF | SUP ;

	Condition: Execute I IFF ;
	IFF: IF pthO CC pthF ;
	CC:Val Expression Val ;
	
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
