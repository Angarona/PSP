#include <stdio.h> // printf
#include <unistd.h> // fork, sleep, wait
#include <sys/types.h> //pid_t
#include <sys/wait.h> //wait

int main(int argc, char const *argv[])
{
    pid_t numPid;
    numPid = fork();
    int num = 1;   
    int estado = 2; 

    if(numPid == 0){ //aqui entrara si hace al hijo
        printf("Soy el hijo con PID: %d.\n", getpid());
        num = num+1;
    } else { //el padre
        printf("Soy el padre con PID: %d.\n", getpid());
        sleep(2);
        pid_t numPid2;
        numPid2 = fork();
        if(numPid2 == 0){
            printf("Soy el hijo con PID: %d.\n", getpid());
            num = num+2;
        } else {
            printf("Soy el padre con PID: %d.\n", getpid());
            sleep(2);
            wait(NULL);
        }
        
        
    }
    printf("Hola, num es: %d\n", num);
    return 0;
}
