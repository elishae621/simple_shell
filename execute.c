#include "shell.h"

void execute(char **parameters)
{
    printf("in execute\n");
    pid_t pid;
    int exev;

    pid = fork();
    if (pid == -1)
        perror(parameters[0]);

    if (pid == 0)
    {
        int i = 0;
        while (parameters[i])
        {
            printf("%s\n", parameters[i]);
            i++;
        }
        exev = execve(parameters[0], parameters, environ);
        if (exev == -1)
            perror("Error");
        else
            perror("Command does not exist");
    }
    wait(NULL);
}