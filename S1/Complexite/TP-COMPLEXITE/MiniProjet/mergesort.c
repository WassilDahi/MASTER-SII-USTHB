#include<stdlib.h> 
#include<stdio.h> 
#include<time.h>

// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r) 
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = r - m; 

	/* create temp arrays */ 
	int* L = (int*)malloc(sizeof(int) * n1);
	int* R = (int*)malloc(sizeof(int) * n2);

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++) 
		L[i] = arr[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = arr[m + 1+ j]; 

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = l; // Initial index of merged subarray 
	while (i < n1 && j < n2) 
	{ 
		if (L[i] <= R[j]) 
		{ 
			arr[k] = L[i]; 
			i++; 
		} 
		else
		{ 
			arr[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 

	/* Copy the remaining elements of L[], if there 
	are any */
	while (i < n1) 
	{ 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 

	/* Copy the remaining elements of R[], if there 
	are any */
	while (j < n2) 
	{ 
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 
free(L);
free(R);
} 

/* l is for left index and r is right index of the 
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
	if (l < r) 
	{ 
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = l+(r-l)/2; 

		// Sort first and second halves 
		mergeSort(arr, l, m); 
		mergeSort(arr, m+1, r); 

		merge(arr, l, m, r); 
	} 
} 



/* Driver program to test above functions */
int main() 
{ 
	  time_t t;
     srand((unsigned) time(&t));

    int *tab=NULL;
    double debut , fin,tps ;
    double x;
  //  long long max={5*pow(10,4),pow(10,5),2*pow(10,5),4*pow(10,5),8*pow(10,5),1.6*pow(10,6),3.2*pow(10,6),6.4*pow(10,6),12.8*pow(10,4),25.6*pow(10,6),51.2*pow(10,6),1.024*pow(10,6),2.048*pow(10,6)},i=0;
    long long max=25000,i=0,j;
/*6250	12500	25000	50000	100000	200000	400000	800000	1600000	3200000 6400000*/

    

  tab=(int*)malloc(max*sizeof(int));


    while(i<max)
    {	
	tab[i]=i;
	//tab[i]=max-i;
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

	mergeSort(tab, 0, max - 1); 
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
