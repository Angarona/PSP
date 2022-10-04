#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
//tiene que estar declara antes del main.
//cambiar el comportamiendo de una señal hay que hacer una funcion.
void manejadorSenyal(int numSenyal);

int main(int argc, char const *argv[])
{
    signal(SIGUSR1, manejadorSenyal); //se puede marcar con el ID que en este caso seria 10.
    //signal(SIGUSR2, manejadorSenyal); //para que los dos tengan la misma funcion.
    printf("PID: %d\n", getpid());
    pause(); //pause es mejor que sleep, porque para indifenidamente, hasta que le llega una señal.
    //sleep()
    return 0;
}
//el proceso a salido con un codigo de señal que no esta definido correctamente (lo marcara con un punto rojo).

// Lo que va a hacer la señal .

void manejadorSenyal(int numSenyal)
{
    printf("He recibido una señal número: %d \n", numSenyal);
}

// aparte de tener la funcion kill en consola, tambien la tengo como funcion-> int kill(pid_t pid, int sig);