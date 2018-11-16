#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/wait.h>
#include <sys/types.h>
void *thread_function(void *val) { //le code a executer par un thread

*val =   *val* *val ;

sleep(6);

pthread_exit((void*)(*val));

}
int main(){
int j;
pthread_t tid;

int tab[5]={2,3,4,5,6};
for (j=0;j<5;j++)
{
pthread_create(&tid, NULL, (void*)thread_function, (void*) &tab[j]);


//pthread_join(tid, (void **)&i);


}

for(j=0;j<5;j++)
{
printf("%d\n",tab[j]);
}



return 0; 

}
