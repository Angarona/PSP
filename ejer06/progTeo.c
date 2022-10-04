#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>

void manejadorSenyal(int numSenyal);

int main(int argc, char const *argv[])
{
    pid_t p;
    p = fork();
    if(p == 0){ //soy el hijo
        printf("[HIJO]: En un segundo le envio la señal.\n");
        sleep(1);
        kill(getppid(),SIGUSR1);
        printf("[HIJO]: Señal enviada, en un segundo terminaré.\n");
        sleep(1);


    }else{ //soy el padre
        signal(SIGUSR1, manejadorSenyal);
        printf("[PADRE]: Me quedo esperando la señal del hijo.\n");
        pause();
        int estado;
        printf("[PADRE]: Me quedo esperando la finalización del hijo\n");
        p = wait(&estado);
        
        printf("[PADRE]: El hijo %d ha terminado con estado %d\n",p, WEXITSTATUS(estado));
    }


    return 0;
}

void manejadorSenyal(int numSenyal)
{
    printf("[PADRE]: He recibido una señal número: %d \n", numSenyal);
}
