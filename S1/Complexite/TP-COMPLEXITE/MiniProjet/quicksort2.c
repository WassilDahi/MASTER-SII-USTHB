
#include<stdio.h> 
#include <time.h>
#include<stdlib.h>

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(int* data, int left, int right)
{
	int x = data[right];
	int i = (left - 1);

	for (int j = left; j <= right - 1; ++j)
	{
		if (data[j] <= x)
		{
			++i;
			Swap(&data[i], &data[j]);
		}
	}

	Swap(&data[i + 1], &data[right]);

	return (i + 1);
}

void QuickSortIterative(int* data, int count) {
	int startIndex = 0;
	int endIndex = count - 1;
	int top = -1;
	int* stack = (int*)malloc(sizeof(int) * count);

	stack[++top] = startIndex;
	stack[++top] = endIndex;

	while (top >= 0)
	{
		endIndex = stack[top--];
		startIndex = stack[top--];

		int p = Partition(data, startIndex, endIndex);

		if (p - 1 > startIndex)
		{
			stack[++top] = startIndex;
			stack[++top] = p - 1;
		}

		if (p + 1 < endIndex)
		{
			stack[++top] = p + 1;
			stack[++top] = endIndex;
		}
	}

	free(stack);
}
int main() 
{ 
	  time_t t;
     srand((unsigned) time(&t));

    int *tab=NULL;
    double debut , fin,tps ;
    double x;
  //  long long max={5*pow(10,4),pow(10,5),2*pow(10,5),4*pow(10,5),8*pow(10,5),1.6*pow(10,6),3.2*pow(10,6),6.4*pow(10,6),12.8*pow(10,4),25.6*pow(10,6),51.2*pow(10,6),1.024*pow(10,6),2.048*pow(10,6)},i=0;
    long long max=400000,i=0,j;
/*6250	12500	25000	50000	100000	200000	400000	800000	1600000	3200000 6400000*/

    

  tab=(int*)malloc(max*sizeof(int));


    while(i<max)
    {	
	//tab[i]=i;
	tab[i]=max-i;
        //tab[i]=rand()% 2000000;
       
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

	QuickSortIterative(tab,max); 
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
