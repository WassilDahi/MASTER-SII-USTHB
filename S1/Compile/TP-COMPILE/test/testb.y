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
%token bfor plus egal moins parfer parouv inf sup division
%start S
%type <nom> idf

%%

S: accoouv accofer




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