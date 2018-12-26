#include <sys/sem.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int semcreate ( key_t cle, int n ) {
 
    int semid = semget(cle,n,IPC_CREAT|IPC_EXCL|0666);
    
    if (semid == -1 ) {
        printf("\n ce group existe deja, recuperation de son id encours");
        semid = semget(cle,4,IPC_EXCL);
    }
    
    return semid;
}

int seminit ( int idsem, int numsem, int initval ) {
    
    int status;
    
    if ( numsem == -1 ) {
        status = semctl(idsem,0,SETALL,initval);
    } else {
        status = semctl(idsem,numsem,SETVAL,initval);
    }
    
    if ( status == -1 ) printf("\nErreur lors de d'initialisation ");
}

int semdelete( int semid ) {
    return semctl (semid, 0, IPC_RMID,0) ;
}

void afficher_groupe( int semid , int n) {
    
    printf("\n");
    for ( int i=0; i<n; i++) {
        printf("%d\t",semctl(semid,i,GETVAL,0));
    }
}
int P(int semid, int numSem)
{
int pp;
struct sembuf sempar ;
sempar.sem_num = numSem ;
sempar.sem_op = -1 ;
sempar.sem_flg = 0;
if (semop(semid, &sempar, 1) == -1)
perror("Erreur operation P");
return pp;
}
int V(int semid, int numSem)
{
int pp;
struct sembuf sempar ;
sempar.sem_num = numSem ;
sempar.sem_op = 1 ;
sempar.sem_flg = 0;
if (semop(semid, &sempar, 1) == -1)
perror("Erreur operation P");
return pp;
}
int Z(int semid, int numSem)
{
int pp;
struct sembuf sempar ;
sempar.sem_num = numSem ;
sempar.sem_op = 0 ;
sempar.sem_flg = 0;
if (semop(semid, &sempar, 1) == -1)
perror("Erreur operation P");
return pp;
}
