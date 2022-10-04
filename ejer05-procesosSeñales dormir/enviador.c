//Va a crear un PID y enviar una señal.
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h> //atoi
//char[] -> es una cadena de caracteres ---- el PID lo has de pasar a cadena ( int 52335 -> char[] 52335)
// atoi("234") para pasar un int a cadena
int main(int argc, char const *argv[]) //argc ->  contador de argumentos(el nombre cuenta)  *argv[]-> vector de argumentos
{
    if(argc !=2){
        fprintf(stderr,"\nError, el programa debe tener un parámetro\n\n");
        fprintf(stdout, "Uso del programa: \n\t %s <num_pid>\n\n", argv[0]);
        exit(-1);
    }
    pid_t pidParametro = atoi(argv[1]);
    kill(pidParametro, SIGUSR1);




    return 0;
}
