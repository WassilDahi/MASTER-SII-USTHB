# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
#include <sys/wait.h>
void main(int argc, char *argv[]){
int pid,i;
int status ;
pid_t fils_pid ;
if (argc == 1) {
printf("\nLe programme n'a reçu aucun argument\n");
}

else {
for (i = 1; i < argc; i++) {
pid = fork ( ) ;
if (pid == - 1)
{ /* code si échec : */
printf ( " le fork ( ) a échoué \n " );
exit(0) ;
}
if (pid == 0)
{ printf("je suis le fils %d \n de pid %d mon pere est le processus de pid %d \n , j'exécute la commande %s \n",i,getpid(),getppid(),argv[1]);
fils_pid = getpid();
/*exec(argv[i]);
perror("execvp"); */
exit(0) ;
}
else
{ wait (&status) ;
printf(" \n fin d'execution de processus fils %d ", fils_pid);
}
}
}
}