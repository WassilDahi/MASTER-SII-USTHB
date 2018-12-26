#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void heapify(int arr[], int n, int i)
{
    int x;
    int largest = i; // Initialize largest as root
	int l = 2*i + 1; // left = 2*i + 1
	int r = 2*i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i)
	{
        x=arr[i];
        arr[i]=arr[largest];
        arr[largest]=x;


		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}
}

// main function to do heap sort
void heapSort(int arr[], int n)
{int x;	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element from heap
	for (int i=n-1; i>=0; i--)
	{
		// Move current root to end
		x=arr[0];
        arr[0]=arr[i];
        arr[i]=x;


		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}



// Driver program
int main()
{
	     time_t t;
     srand((unsigned) time(&t));

     int *tab=NULL;
     double x,debut,fin,tps;

    long long max=102400000,i=0,j;

    /* max = 6250 , 12500 , 25000, 50000 , 100000, 200000, 400000 , 800000 , 1600000 , 3200000 */

    tab=(int*)malloc(max*sizeof(int));

    // création du tableau
    while (i<max){
            // ordre inverse
           // tab[i]=max-i;

            // ordonné
            //tab[i]=i;

            // aléatoire
            tab[i]=rand()%200000;
i++;
    }


  /*  i=0;
while(i<max){
 printf("%d  ",tab[i]);
 i++;
}*/
	debut=clock();


	heapSort(tab,max);

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
