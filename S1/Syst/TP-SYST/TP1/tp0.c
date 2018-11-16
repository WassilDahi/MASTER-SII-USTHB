# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
#include <sys/types.h>

int main()
{
    pid_t p1,p2,p3,p4,p5;
    int n;

        p1 = fork();
        if (p1==0)
        {   
            printf("Le pere : %d et son fils P1 : %d\n",getppid(),getpid());
            n=getppid();
            p3=fork();
            if(p3==0)
            {
                printf("Le pere : %d et son fils P3 : %d\n",getppid(),getpid());
                sleep(10);
                exit(0);
            }
            p4=fork();
            if(p4==0)
            {
                printf("Le pere : %d et son fils P4 : %d\n",getppid(),getpid());
                sleep(10);
                exit(0);
            }
            sleep(10);
            exit(0);
        }

        p2=fork();
        if(p2==0)
        {
            printf("Le pere : %d et son fils P2  : %d\n",getppid(),getpid());
            sleep(10);
            exit(0);
        }

        wait(0);

        p5=fork();
         if(p5==0)
        { printf("Le pere : %d et son fils P5  : %d\n",getppid(),getpid());
            sleep(10);
            exit(0);
        }

        sleep(10);

        return 0;   
}
