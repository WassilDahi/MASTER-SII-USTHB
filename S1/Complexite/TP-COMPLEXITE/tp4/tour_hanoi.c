#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long nb=0;

void tourhanoi(int n, int a, int c ,int b)
{
    
 if (n>=1)
 {
  tourhanoi(n-1,a,b,c);
  nb++;
    tourhanoi(n-1,c,a,b);
 }
}


int main(int argc, char const *argv[])
{


    double debut , fin,tps ;

debut = clock();
tourhanoi(5,1,2,3);
fin=clock();
tps=(double)(fin-debut) / CLOCKS_PER_SEC ;
printf("nombre de deplacement = %lld , temps = %lf\n",nb,tps);

    return 0;
}


/*

T(n)=aT(n/2)+O(N^c)

si a < b^c >>>>>> T(N)=O(N^c)
si a= b^c  >>>>>> T(N)=O(N^c logbase(b)(N))
si a > b^c >>>>>> T(N)=O(N^(logbase(b)(a)))

*/
