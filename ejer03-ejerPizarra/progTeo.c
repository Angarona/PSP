#include <stdio.h> // printf
#include <unistd.h> // fork, sleep, wait
#include <sys/types.h> //pid_t
#include <sys/wait.h> 
int main(int argc, char const *argv[])
{
    pid_t padre, hijo1, hijo2;
    padre = getpid();
    hijo1= fork();
    if(hijo1 == 0){
        printf("Soy el hijo 1 = pid: %d. \n", getpid());
        return 1 ;
    }
    else{
        printf("SOY EL PADRE (PID:%d) Y MI HIJO (PID:%d).\n", padre, hijo1);
        hijo2 = fork();
        if (hijo2 == 0){
            printf("Soy el hijo 2 = pid %d. \n", getpid());
            return 2;
        }
        else{
            printf("SOY EL PADRE (PID:%d) Y MI HIJO (PID:%d).\n", padre, hijo2);
            int estado;
            pid_t hijofinalizado;
            for(int i = 0; i<2 ; i++){
                hijofinalizado = wait(&estado);
                printf("Un hijo (PID: %d) ha finalizdo con estado %d. \n", hijofinalizado, WEXITSTATUS(estado));

            }
        }
    }

    return 0;
}
