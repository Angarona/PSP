#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>

void manejadorSenyal(int numSenyal);

int main(int argc, char const *argv[])
{
    //pid_t padre = getppid();  se refiere al padre de todo (la consola)
    if(fork()==0){
        sleep(1);
        kill(getppid(),SIGUSR1); //se llama al padre  aqui porque asi no llama a la consola
        
    } else{
        signal(SIGUSR1, manejadorSenyal);
        pause();
        int estado;
        pid_t hijofinalizado;
        hijofinalizado = wait(&estado);
        printf("El hijo %d esta en estado %d\n",hijofinalizado, WEXITSTATUS(estado));
    }
    
    return 0;
}

void manejadorSenyal(int numSenyal)
{
    printf("He recibido una señal número: %d \n", numSenyal);
}
