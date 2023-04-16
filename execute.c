#include "shell.h"

void execute(char *command, char **parameters, char **envp)
{
    pid_t pid;
    int exev;

    pid = fork();
    if (pid == -1)
        perror(command);

    if (pid == 0)
    {
        exev = execve(command, parameters, envp);
        if (exev == -1)
            perror("Error");
        else
            perror("Command does not exist");
    }
    wait(NULL);
}