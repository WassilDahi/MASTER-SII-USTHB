#include <stdio.h>
#include <stdlib.h>

void tourhanoi(int n, char *a, char *c ,char *b)
{
 if (n==1)
 {
     return ;
 }
  tourhanoi(n-1,a,b,c);
  printf("deplacer le disque restant de %d vers %d  \n",a,b);
    tourhanoi(n-1,c,a,b);
 
}


int main(int argc, char const *argv[])
{



tourhanoi(n,"A","C","D");

    return 0;
}


/*

T(n)=aT(n/2)+O(N^c)

si a < b^c >>>>>> T(N)=O(N^c)
si a= b^c  >>>>>> T(N)=O(N^c logbase(b)(N))
si a > b^c >>>>>> T(N)=O(N^(logbase(b)(a)))

*/
