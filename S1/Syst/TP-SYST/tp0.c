# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
#include <sys/types.h>

void main(){
int pid,i;
pid = fork () ;
if (pid == - 1)
{ /* code si échec : */
printf ( "le fork ( ) a échoué \n");
exit(0) ;
}
if (pid > 0){ }
if (pid ==0)
{ sleep(5); printf("\tfils : %d \t pere: %d\n",getpid(),getppid()); }

}
