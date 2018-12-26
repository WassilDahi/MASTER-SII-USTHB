#include<sys/ipc.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>


int p(int semid)
{
struct sembuf sempar;
sempar.sem_num=0;
sempar.sem_op=-1;
sempar.sem_flg=SEM_UNDO;
return semop(semid,&sempar,1);
}

int v(int semid)
{
struct sembuf sempar;
sempar.sem_num=0;
sempar.sem_op=1;
sempar.sem_flg=SEM_UNDO;
return semop(semid,&sempar,1);
}

int main()
{
int pid=1,i=0, n,sf;
sf=semget(IPC_PRIVATE,1,IPC_CREAT|0666);
semctl(sf,0,SETVAL,0);
 
printf("Nb process =  ");
scanf("%d",&n);

while(pid!=0 && i<(n))
{

pid=fork();
if(pid==0)
{
if (i<(n))
{
sleep(rand()%3+1);
printf(" processus  %d  termin\é \n\n",i+1);
v(sf); p(sf);
 
}
}

i++;
wait();
}




if (pid>0 && i==(n-1))
{
 
 v(sf);
 
}
}
