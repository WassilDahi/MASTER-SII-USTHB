#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <string.h>

typedef union semun {
    int              val;   
    struct semid_ds *buf;    
    unsigned short  *array;  
    struct seminfo  *__buf; 
}semun;

/***********************************************************/

int semcreate (key_t key, int n){

int semid = semget(key , n , IPC_CREAT | IPC_EXCL | 0666 );

if(semid == -1){
	semid=semget(key , n ,0);
	printf("groupe de sémaphore deja crée et son id = %d \n",semid);
		}

return semid;
}

/************************************************************/

int seminit(int semid , int semnum, int initval){

int ret = semctl(semid, semnum , SETVAL , initval);
if(ret == -1) perror("seminit error !\n");
return ret;
}

/************************************************************/


 
void P(int semid , int n) {

  struct sembuf sempar ;

  sempar.sem_num = n ;
  sempar.sem_op = -1 ;
  sempar.sem_flg = 0 ;

  if ( semop(semid,&sempar,1) == -1)
    perror("Erreur lors du down") ;
}

/************************************************************/


void V(int semid , int n) {

  struct sembuf sempar ;

  sempar.sem_num = n ;
  sempar.sem_op = 1 ;
  sempar.sem_flg = 0 ;

  if (semop(semid,&sempar,1) ==-1)
    perror("Erreur lors du up") ;
}

/************************************************************/

void semdelete(int semid){

  printf("destruction du s\\'emaphore %d \n",semid) ;

  if(semctl(semid,0,IPC_RMID,0) == -1)
    perror("Erreur lors de la destruction du semaphore") ;
}

 


int main(int argc , char *argv[])
{
	key_t key =ftok("/home/wassil/studies/Master-SII/S1/Syst/TP-SYST", 'h');
	int sem = semcreate(key,1);
	int refresh = 0;
	seminit(sem ,refresh, 0);

	pid_t pid;
	int Val ,preVal= 11, i = 0,j = 0;
	int s = (int) atoi(argv[1]);
	char* c = (char*) argv[1];

	while(1)
	{
		pid = fork() ;
		if(pid == -1)
		{
			printf("erreur de création de fils");
			exit(0);
		}

		if(pid == 0 )//precessus fils1
		{
			P(sem,refresh);//attendre jusqu'a libération

			execlp("ipcs","ipcs","-s","-i",c,NULL);
			printf("erreur d'execution !! \n");
			exit(0);
			

		}
		else//le pere
		{
			Val = semctl(s, 0 , GETVAL , Val);			

			if(preVal != Val)//s'il y'a une modification sur le semaphore dont le pid et en entrée
			{
				preVal = Val;   //Comparaison d'état initial et d'état de changement si ça change
						
				V(sem,refresh);	//Affichage du résultat quand le fils se réveil
				
				wait();			
			}

		}
	
	sleep(1);
	}
	return 0;
	
}
