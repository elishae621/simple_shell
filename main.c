#include "shell.h"

/**
 * main - runs the prompt and get the command
 * Return: 0
 */
int main(void)
{
    char cmd[100], command[100], *parameters[20];
    char *envp[] = {(char *)"PATH=/bin", 0};
    pid_t pid;
    int exev;

    while (1)
    {
        // printf("command before prompt: %s, value of cmp is %i\n", command, strcmp(command, "exit"));

        type_prompt();
        read_command(command, parameters);
        // printf("command: %s\n", command);
        // printf("parameters: %s\n", parameters[0]);

        // pid = fork();
        // if (pid == -1)
        //     return (-1);

        // if (pid == 0)
        // {
        //     printf("\nin child\n");
        //     // if (strcmp(command, "exit") == 0)
        //     //     break;
        //     strcpy(cmd, get_command_location(command));
        //     printf("cmd location: %s", cmd);
        //     if (strcmp(cmd, ""))
        //     {
        //         exev = execve(cmd, parameters, envp);
        //         if (exev == -1)
        //             perror("Error");
        //     }
        //     else
        //         perror("Command does not exist");
        // }
        // else
        // {
        //     wait(NULL);
        // }
    }
    return 0;
}