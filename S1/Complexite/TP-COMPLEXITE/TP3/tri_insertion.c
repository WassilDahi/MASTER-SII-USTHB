

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
    double x;
  //  long long max={5*pow(10,4),pow(10,5),2*pow(10,5),4*pow(10,5),8*pow(10,5),1.6*pow(10,6),3.2*pow(10,6),6.4*pow(10,6),12.8*pow(10,4),25.6*pow(10,6),51.2*pow(10,6),1.024*pow(10,6),2.048*pow(10,6)},i=0;
    long long max=3200000,i=0,j;
/*6250	12500	25000	50000	100000	200000	400000	800000	1600000	3200000 6400000*/

    

  tab=(int*)malloc(max*sizeof(int));


    while(i<max)
    {
	tab[i]=max-i;
        //tab[i]=rand()% 2000000;
       // printf("%d\t ",tab[i]);
        i++;
    }
 

    /*i=0;
	     while(i<max)
	    {
		printf("%d  ",tab[i]);
    i++;
	    }
printf("\n\n");*/

	debut = clock();
    for(i=0;i<=max-1;i++)
  {
      x=tab[i];
      j=i;
      while((j>0) &&(tab[j-1]>x))
      {
        tab[j]=tab[j-1];
        j=j-1;
      }
      tab[j]=x;
  }
	    fin=clock();

	/*i=0;
	     while(i<max)
	    {
		printf("%d  ",tab[i]);
    i++;
}*/
	    
	
	    tps=(double)(fin-debut) / CLOCKS_PER_SEC ;

	    printf("\n--------n=%lld  tps= %lf\n",max,tps);


return 0;
}
