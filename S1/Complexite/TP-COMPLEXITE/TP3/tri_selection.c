#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>




int main(int argc, char const *argv[])
{   
   
     time_t t;
     srand((unsigned) time(&t));

    int *tab=NULL;
    double debut , fin,tps ;

    long long max=100000,i=0,j;
    

  tab=(int*)malloc(max*sizeof(int));
printf("\n");

    printf("------------- Creation du tableau ----------------\n");
    while(i<max)
    {   // pour avoir un tab ordonné  inversé
        //tab[i]=max-i;
       
       //  pour avoir inversé
//tab[i]=rand()% 2000000;
       // pour avoir ordonné
tab[i]=i; pour avoir un tab 
        i++;
    }
    printf("------------- Creation du tableau ---------------- Termine !");
   
   

 /* --------------------------------- Tri selection ---------------------------------------*/
    debut=clock();


     printf("\n------------- Debut du tri par selection  ----------------\n");
    i=0;
    long long indice_max,limit=max;
    while(i<limit)
    {
    
    j=i;indice_max=0;
    // recherche du max    
    while(j < limit)
    {
        
        if(tab[j] < tab[indice_max])
            indice_max = j;
        j++;
    }

    long long x;
  // permutations 
    x=tab[indice_max];
    tab[indice_max]=tab[i];
    tab[i]=x;

    i++;

    }
    
    fin=clock();

printf("\n\n");

 // affichage du temps 
printf("\n------------- Fin du tri par selection  ----------------\n");
    tps=(double)(fin-debut) / CLOCKS_PER_SEC ;

    printf("\n----------------------------------------------------------------------------------\ntps= %.02lf\n",tps);

    
    return 0;
}
