/*****************************************************************
Nome: Anderson Murillo                  RA: 248221
Nome: Isaac do Nascimento Oliveira      RA: 247175
*******************************************************************/

#include "stdio.h"
#include "string.h"
#include "unistd.h"

#define MAX_LINE_LEN 1024 // max shell line len
#define MAX_CMD_LEN 256 // max cmd or args len
#define MAX_ARGS_LEN 256 // max cmd or args len

void read_command(char *cmd, char *args[]) {
    char line[MAX_LINE_LEN];

    // get input
    printf("simple_shell$: ");
    fgets(line, sizeof(line), stdin);

    // extract words in line
    char *token = strtok(line, " ");
    strcpy(cmd, token);

    int argcount = 0;
    while (token != NULL) {
        args[argcount++] = strtok(line, " ");
        token = args[argcount-1];
    }

}


void verify_command(char *cmd, char *dir) {
    
}

int main(int argc, char *argv[]) {
    char cmd[MAX_CMD_LEN];
    char *args[MAX_ARGS_LEN];

    while (1) {
        int status;
        __pid_t pid;

        // read and check input
        read_command(cmd, args); /* reads cmd and args
         from command line */
        verify_command(cmd, argv[1]);
        if (!verify_command) {
            printf("ERROR: Invalid command.");
            continue;
        }
        
        // valid command
        pid = fork();
        if (pid == 0) {
            execv(cmd, args);
            exit(1);
        }
        else {
            wait(&status);
        }
    }
}