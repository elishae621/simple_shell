#include "shell.h"

/**
 * main - runs the prompt and get the command
 * Return: 0
 */
int main(void)
{
    char *cmd, *command, **parameters, *path, *pathname;
    char *envp[] = {(char *)"PATH=/bin", 0};
    int numParameters = 20;
    linklist *head = NULL;

    cmd = malloc(sizeof(char) * 100);
    command = malloc(sizeof(char) * 100);

    /* Allocate memory for the array of string pointers */
    parameters = (char **)malloc(numParameters * sizeof(char *));

    /* Check if memory allocation was successful */
    if (parameters == NULL)
    {
        perror("Failed to allocate memory for parameters\n");
    }

    /* Allocate memory for each individual string in the array */
    for (int i = 0; i < numParameters; i++)
    {
        parameters[i] = (char *)malloc(100 * sizeof(char));
    }

    while (1)
    {
        type_prompt();
        read_command(command, parameters);
        printf("command: %s\n", command);
        printf("parameters: %s\n", parameters[1]);

        path = _getenv("PATH");
        head = linkedpath(path);

        pathname = get_command_location(command, head);

        execute(command, parameters, envp);
        strcpy(cmd, command);
        printf("cmd: %s", cmd);
        printf("cmd location: %s", command);
        if (strcmp(command, ""))
        {
        }
    }
    return 0;
}