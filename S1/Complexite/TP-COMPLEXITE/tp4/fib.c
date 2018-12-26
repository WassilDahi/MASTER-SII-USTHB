#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long fib(long long n)
{
    if (n==0 || n==1 ){
return n;
}
else {
return fib(n-1) + fib(n-2);
}

}

long long fib2(int n){
	int f[n],i;
	if(n >= 0){


 	if((n == 0)||(n == 1)){
 		f[n] = n;
 	}
     
     else{
 		f[0] = 0;
		f[1] = 1;
 		for(i=2;i<=n;i++){
 			f[i] = f[i-1] + f[i-2];
 		}
 	}
 	return f[n];
 	}
     
     
     else{
 		return -1;
 	}
}

int main(int argc, char const *argv[])
{

double debut , fin,tps ;
long long x;
  

for (int i=51;i<=60;i++)
{
debut = clock(); 
x=fib(i);
fin=clock();
tps=(double)(fin-debut) / CLOCKS_PER_SEC ;
printf(" n =%d temps = %lf\n",i,tps);
}



    return 0;
}


/* complexité spatiale 
E(n)=C+ max(E(n-1),E(n-2))

E(n)=C+E(n-1)

variable locale n ,
*/