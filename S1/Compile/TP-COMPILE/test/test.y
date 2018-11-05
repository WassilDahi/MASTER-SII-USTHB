%{
 #include <stdio.h>
	
	extern FILE *yyin;
	extern int l,c;

int yylex();
int yyerror();

%}

%union{
char *nom;
int ent;
}

%token idf entier reel virg pvirg Integ real accoouv accofer 
%token bfor plus egal moins parfer parouv inf sup division s
%start S
%type <nom> idf

%%

S:dec accoouv corps accofer  |dec accoouv s corps accofer  ;

dec: type pidf pvirg  dec|%empty;
pidf: idf virg pidf|idf  ; 
type: Integ  | real  ;
corps: INSTS  ;
INSTS: boucle INSTS | affect INSTS  |%empty  ;
affect: exp egal exp pvirg | exp egal idf pvirg | exp egal nombre pvirg ;
exp: idf plus exp  | idf moins exp | nombre plus exp  | nombre moins exp | idf sup idf  | idf sup nombre  | nombre sup idf  | idf inf idf  | idf inf nombre  | nombre inf idf  | idf egal idf  | nombre egal idf  | idf egal nombre  |%empty ;
boucle: bfor parouv exp parfer  ;
nombre: entier  | reel  ;

%%

int yyerror(char *msg)
{
	printf("%s\n\n",msg);
	//exit(0);
return 0 ;
}

int main()
{
	yyin=fopen("test.txt","r");
	yyparse();

	return 1;
}