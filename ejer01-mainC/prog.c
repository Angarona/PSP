#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    fork(); //duplica
    fork(); // no se sabe en el orden en el cual crea las divisiones.
    printf("Mi PID es: %d y mi padre es %d \n", getpid(), getppid());
    return 0;
}
//para crear el ejecutable gcc "x".c -o "x".exe

//funcion que signifirca fork - dividir - fork()
// comando para ver que librerias necestia man -a "x" funcion
// funcion que sirve para imprimir el PID -> getppid (padre) getpid(hijo)
// ps para ver el PID de la consola