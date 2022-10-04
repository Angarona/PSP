#include <unistd.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    //execl("/usr/bin/firefox", "firefox", "https://leagueoflegends.com/", NULL); 
    //mandarle null para que se entere de que ya hemos acabado poner rutas
    char* v[]= {"firefox", "https://leagueoflegends.com/", NULL}; //char* -> String
    execv("/usr/bin/firefox", v);

    //system("ls -l > ls.txt");
    return 0;
}
