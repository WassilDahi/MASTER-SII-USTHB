%{
    #include <string.h>
    int l=1,c=0;
%}

t [ \t]
S [\n]
idf [a-z]+
entier [0-9]+
reel [0-9]+\.[0-9]*|\.[0-9]+

%%

{idf} {printf("Identifiant : %s",yytext);printf("\n");c=c+strlen(yytext);}
{entier} {printf("entier : %s",yytext);printf("\n");c=c+strlen(yytext);}
{reel} {printf("reel : %s",yytext);printf("\n");c=c+strlen(yytext);}
{S} {l++;c=0;}
{t} {c=c+strlen(yytext);}

. {printf("erreur lexicale ligne %d colonne %d entite %s\n",l,c,yytext);}

%%
int main()
{   yyin=fopen("input.txt","r");
    if (yyin==NULL)
    {
        printf("erreur ouverture");
    }
    else {
        yylex();
    }
    return 0;
}