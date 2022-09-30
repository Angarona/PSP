#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
//tiene que estar declara antes del main.
//cambiar el comportamiendo de una señal hay que hacer una funcion
void manejadorSenyal(int numSenyal);

int main(int argc, char const *argv[])
{
    signal(SIGUSR1, manejadorSenyal);
    printf("PID: %d\n", getpid());
    sleep(20);
    return 0;
}

// Lo que va a hacer la señal 

void manejadorSenyal(int numSenyal)
{
    printf("He recibido una señal número: %d \n", numSenyal);
}
