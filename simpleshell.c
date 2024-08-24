/*****************************************************************
Nome: Anderson Murillo          RA: 248221         Turma: A
Nome:                           RA:
Nome: Anderson Murillo                  RA: 248221
Nome: Isaac do Nascimento Oliveira      RA: 247175
*******************************************************************/

#include "stdio.h"
#include "unistd.h"
#include "string.h"


void read_commands(char cmd[], char *argv[]) {
    scanf("%s", &argv);
    printf("simple-shell$: ");
    scanf("%s", &cmd);
}



void main(int argc, char *argv[]) {
    while(1) {
        char cmd[256];
        int status;
        __pid_t pid;
        read_commands(cmd, argv);

        pid = fork();
        if (pid == 0) {
            execv(argv[1], cmd);
            exit(1);
        }
        else {
            wait(&status);
        }
    }
}


int main(int argc, char *argv[]) {
   
}
