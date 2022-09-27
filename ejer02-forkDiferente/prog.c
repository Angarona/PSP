#include <stdio.h> // printf
#include <unistd.h> // fork, sleep, wait
#include <sys/types.h> //pid_t
#include <sys/wait.h> //wait


int main(int argc, char const *argv[])
{
    pid_t numPid;
    int num = 12;

    numPid = fork();

    if(numPid == 0){ //proceso hijo devolvera cierto y entrara en el if
        printf("Soy el hijo y mi PID es %d. \n",getpid()); //getpid() -> para llamar el PID.
        num = num + 3;
        sleep(1); //duerme el hijo durante "x" segundos.
    } else{
        printf("Soy el padre, mi pid es %d. \n", getpid());
        int estado = 25; //Declarar un entero donde el wait guardara informacion sobr el retorno.
        pid_t pidFinalizado = wait(&estado); //le pasamos la dirección de memoria del estado.
        //wait(NULL); //el wait espera a que el hijo acabe.
        printf("El hijo con PID: %d finalizó con estado %d, el valor de estado es :%d\n", 
                pidFinalizado, WEXITSTATUS(estado), estado); //parte los ultimos BITS y te los devuelve (codificados)
            // el "valor" de estado no tiene ningun sentido practivo, ya que en todos los bits de ese entero el 
            //wait codifica diferentes datos que nos fan informacion sobre la finalizacion de ese proceso
            //más info en 'man wait'
        sleep(1);
    }
    printf("Hola, num es: %d\n", num);

    // son dos memorias diferentes. No se comunican. 

    // que el hijo espere un segundo. Los hijos no pueden esperar al padre, pero el padre a sus hijos si.

// int * -> pasar una direccion de memoria.

    return 0;
}
