// Optimized implementation of Bubble sort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>





int main()
{
     time_t t;
     srand((unsigned) time(&t));

     int *tab=NULL;
     double x,debut,fin,tps;

    long long max=1600000,i=0,j;

    /* max = 6250 , 12500 , 25000, 50000 , 100000, 200000, 400000 , 800000 , 1600000 , 3200000 */

    tab=(int*)malloc(max*sizeof(int));

    // création du tableau
    while (i<max){
            // ordre inverse
            //tab[i]=max-i;

            // ordonné
           // tab[i]=i;

            // aléatoire
           tab[i]=rand()%200000;
i++;
    }

    /*
    i=0;
while(i<max){
 printf("%d  ",tab[i]);
 i++;
}*/
	debut=clock();

int bool;
for (i = 0; i < max-1; i++)
{
	bool =0;
	for (j = 0; j < max-i-1; j++)
	{
		if (tab[j] > tab[j+1])
		{
        x=tab[j];
        tab[j]=tab[j+1];
        tab[j+1]=x;
		bool = 1;
		}
	}

	// IF no two elements were bool by inner loop, then break
	if (bool == 0)
		break;
}
fin = clock();

/*printf("\n");
i=0;
while(i<max){
 printf("%d  ",tab[i]);
 i++;
}*/
tps=(double)(fin-debut)/CLOCKS_PER_SEC;
printf("\nn=%lld tps=%lf\n",max,tps);

	return 0;
}
