
#include<stdio.h> 
#include <time.h>
#include<stdlib.h>


int partition (int arr[], int low, int high) 
{ 
	int pivot = arr[high];
	long long  i = (low - 1);
	long long x;

	for (int j = low; j <= high- 1; j++) 
	{ 
		if (arr[j] <= pivot) 
		{ 
			i++; 
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 

/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
void quickSort(int arr[], int low, int high) 
{ 
	if (low < high) 
	{ 
		/* pi is partitioning index, arr[p] is now 
		at right place */
		long long pi = partition(arr, low, high); 

		// Separately sort elements before 
		// partition and after partition 
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
} 


int main() 
{ 
	  time_t t;
     srand((unsigned) time(&t));

    int *tab=NULL;
    double debut , fin,tps ;
    double x;
  //  long long max={5*pow(10,4),pow(10,5),2*pow(10,5),4*pow(10,5),8*pow(10,5),1.6*pow(10,6),3.2*pow(10,6),6.4*pow(10,6),12.8*pow(10,4),25.6*pow(10,6),51.2*pow(10,6),1.024*pow(10,6),2.048*pow(10,6)},i=0;
    long long max=200000,i=0,j;
/*6250	12500	25000	50000	100000	200000	400000	800000	1600000	3200000 6400000*/

    

  tab=(int*)malloc(max*sizeof(int));


    while(i<max)
    {	
	//tab[i]=i;
	tab[i]=max-i;
        //tab[i]=rand()% 2000000;
       // printf("%d\t ",tab[i]);
        i++;
    }
 
/*
    i=0;
	     while(i<max)
	    {
		printf("%d  ",tab[i]);
    i++;
	    }
printf("\n\n");*/

	debut = clock();

	quickSort(tab, 0, max-1); 
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
