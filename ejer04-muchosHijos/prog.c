//ctrl+shift+I -> Lo ordena todo

#include <stdio.h> // printf
#include <unistd.h> // fork, sleep, wait
#include <sys/types.h> //pid_t
#include <sys/wait.h> //wait
// Definir constatne en C
#define N_HIJOS 150
int main(int argc, char const *argv[])
{
    for (int i = 0; i < N_HIJOS; i++)
    {
        if (fork() == 0) // Codigo de los hijos
        {
            printf("Hola soy el hijo número: %d \n", getpid());
            sleep(1);
            return i; // Para que no sigan ejecutandose cuando salimos.
        }
    }
    int estado;
    int pidHijo;

    for (int i = 0; i < N_HIJOS; i++)
    {
        pidHijo = wait(&estado);
        printf("El hijo %d ha finalizado con valor de retorno %d\n", pidHijo, WEXITSTATUS(estado));
    }
    return 0;
}

//Señales, ctrl+c para cerrar la consola envia una señal SIGINT