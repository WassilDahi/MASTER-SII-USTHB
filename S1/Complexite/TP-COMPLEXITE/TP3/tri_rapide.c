#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int partitionner(int *tableau, int p, int r) {
    int pivot = tableau[p], i = p-1, j = r+1;
    int temp;
    while (1) {
        do
            j--;
        while (tableau[j] > pivot);
        do
            i++;
        while (tableau[i] < pivot);
        if (i < j) {
            temp = tableau[i];
            tableau[i] = tableau[j];
            tableau[j] = temp;
        }
        else
            return j;
    }
}

void quickSort(int *tableau, int p, int r) {
    int q;
    if (p < r) {
        q = partitionner(tableau, p, r);
        quickSort(tableau, p, q);
        quickSort(tableau, q+1, r);
    }
}


int main(int argc, char const *argv[])
{   
   
     time_t t;
     srand((unsigned) time(&t));

    int *tab=NULL;
    double debut , fin,tps ;
  //  long long max={5*pow(10,4),pow(10,5),2*pow(10,5),4*pow(10,5),8*pow(10,5),1.6*pow(10,6),3.2*pow(10,6),6.4*pow(10,6),12.8*pow(10,4),25.6*pow(10,6),51.2*pow(10,6),1.024*pow(10,6),2.048*pow(10,6)},i=0;
    long long max=3.2*pow(10,6),i=0,j;
    

  tab=(int*)malloc(max*sizeof(int));
printf("\n");

    printf("------------- Creation du tableau ----------------\n");
    while(i<max)
    {
        tab[i]=rand()% 20000000;
       // printf("%d\t ",tab[i]);
        i++;
    }
    printf("------------- Creation du tableau ---------------- Termine !");
   
    /*while(i<max-1)
    {
        printf("\r%d ",tab[i]);
        i++;
    }*/

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
        
        if(tab[j] > tab[indice_max])
            indice_max = j;
        j++;
    }

    long long x;

    x=tab[indice_max];
    tab[indice_max]=tab[limit-1];
    tab[limit-1]=x;

    limit--;

    }
    
    fin=clock();

printf("\n\n");
i=0;
     while(i<max)
    {
        printf("%d ... \t\t ",tab[i]);
        i=i+(max/50);
    }
printf("\n------------- Fin du tri par selection  ----------------\n");
    tps=(double)(fin-debut) / CLOCKS_PER_SEC ;

    printf("\n----------------------------------------------------------------------------------\ntps= %.02lf\n",tps);

    
    return 0;
}

