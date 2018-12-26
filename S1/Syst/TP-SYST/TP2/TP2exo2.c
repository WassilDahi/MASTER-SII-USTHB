#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>
#define nb 13 // le nombre a tester si il est premier

int boole=0;// booleen pour savoir dans le main si il est premier ou pas
double sqrt_nb=sqrt(nb);
clock_t t;
// fonction pour diviser la recherche en 4
void *divsearch(void *var){
	double s,e;
	int r=(int*)var;
	switch(r){
		case 1:{
			s=2;
			e=ceil(sqrt_nb/4);
			break;
		}
		case 2:{
			s=ceil(sqrt_nb/4);
			e=ceil(sqrt_nb/2);
			break;
		}
		case 3:{
			s=ceil(sqrt_nb/2);
			e=ceil(3*sqrt_nb/4);
			break;
		}
		case 4:{
			s=ceil(3*sqrt_nb/4);
			e=sqrt_nb;
			break;
		}	
	}
	int j=s;
	t=clock();
// boucle pour chercher les diviseurs
	for(j;j<e;j++){
		if ((nb % j)==0){
if (j==1){
}
else {
boole=1;
			printf(" %llu est un diviseur de %llu \n",j,nb);//affichage des diviseurs
printf(" %llu n'est pas un nombre premier \n",nb);
			printf("temps = %g \n", (double)(clock()-t)/CLOCKS_PER_SEC );				
			break;//exit(0);
}
		}
	}

	pthread_exit((void*)0);
}
int main (void){
//creation des threads
	pthread_t tid1,tid3,tid2,tid4;
	pthread_create(&tid1,NULL,divsearch,(int*)1);
	pthread_create(&tid2,NULL,divsearch,(int*)2);
	pthread_create(&tid3,NULL,divsearch,(int*)3);
	pthread_create(&tid4,NULL,divsearch,(int*)4);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_join(tid3, NULL);
	pthread_join(tid4, NULL);
	
	
	// Si il n'a pas trouvé de diviseurs il affiche qu'il est premier
	if (boole==0){
printf(" %llu est  un nombre premier \n",nb);
printf(" Temps d'execution =  %f \n", (double)(clock()-t)/CLOCKS_PER_SEC );
	
}
					
	return 1 ;
}


























