%{
	#include <stdio.h>
	//#include "ts.h"
	extern FILE *yyin;
	extern int l,c;
	

%}


%token idf entier reel Real Integer aco acf  VIR PVT Const
%token eg ADD SUS MUL DIV pthO pthF ptpt afc INF SUP PointP Diaz
%token INFEG SUPEG DIFF OR AND NEG While Execute IF Comment Sep
%type <nom> idf
 
%%
	S: DIAZ idf aco D I acf ;

	D: Type PointP idf Var  |Type PointP Const idf afc Valeur CST ;
	CST:  PVT  FinD| VIR idf afc Valeur  CST ;
	Valeur: entier | reel;
	Type: Integer  | Real  ;
	Var: VIR idf VAR | PVT FinD ;
	FinD:PVT D |PVT ;
	
 

	I: Affect PVT I | CndCHECK I | Boucle I | Boucle |CndCHECK |Affect PVT ;

	Affect: idf eg Exp  ;
	Exp: Val OP1 | Val ;
	OP1: ADD Exp | SUS Exp | OP2 ;
	OP2: MUL Exp | DIV Exp ;;

	CndCHECK: CHECK Condition ptpt BlocI ;
	Condition: Negation Exp Operateur Exp pthF | Negation Cond pthF ;
	Negation: NEG pthO | pthO;
	Cond: Negation Exp Operateur Exp pthF OrAnd Cond |
	 	Negation Exp Operateur Exp pthF ;
	OrAnd: OR | AND ;
	Operateur: egeg | INF | SUP | INFEG | SUPEG | DIFF ;
	BlocI: Affect PVT Choix | Boucle Choix | CndCHECK Choix;
	Choix: BlocI | ptpt BlocI | ENDCHECK;
	
	Boucle: REPEAT ptpt BInit ;
	BInit: Affect ptpt BCnd ;
	BCnd: Condition ptpt BAffect;
	BAffect: Affect ptpt BlocI2;
	BlocI2: Affect PVT Choix2 | CndCHECK Choix2 | Boucle Choix2 ;
	Choix2: BlocI2 | ENDREPEAT;
%%

int yyerror(char *msg)
{
	printf("%s\n",msg);
	//exit(0);
return 0 ;
}

int main()
{
	yyin=fopen("input.txt","r");
	yyparse();
	
	return 1;
}
