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

// returns the cmd concatenated with the dir
char *concatenate_cmd_with_dir(char *cmd, char *dir) {
    // '/usr/bin/ -> example of dir
    // 'whoiam' -> example of cmd
    // in the end, i have to verify if this kind of thing occurs:
    // '/usr/bin/whoiam'
    char *dir_with_bar, result;
    strcpy(dir_with_bar, strcat(dir, '/'));
    strcpy(result, strcat(dir_with_bar, cmd));
    return result;
}

int main() {
    // argv is the first user input
    // cmd is the command
    // args is what cmd have to do
    char cmd[MAX_CMD_LEN];
    char *args[MAX_ARGS_LEN];
    char argv[MAX_LINE_LEN];

    // the argv[1] is not the whole dir, we have to separate
    // the strings after the blank space to get the dir and work
    // with it
    fgets(argv, sizeof(argv), stdin);

    while (1) {
        int status;
        __pid_t pid;

        // read and check input
        read_command(cmd, args); /* reads cmd and args
         from command line */
        char *result = concatenate_cmd_with_dir(cmd, argv[1]);
        
        // valid command
        pid = fork();
        if (pid == 0) {
            int sucess = execv(result, args);
            if (sucess == -1) {
                printf("ERROR: Invalid command.");
                continue;
            } else {
                exit(1);
            } 
        }
        else {
            wait(&status);
        }
    }
}