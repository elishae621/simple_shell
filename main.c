#include "shell.h"

/**
 * main - runs the prompt and get the command
 * Return: 0
 */
int main(void)
{
    char **parameters, *path, *pathname;
    int numParameters = 20;
    linklist *head = NULL;

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
        read_command(parameters);

        path = _getenv("PATH");
        head = linkedpath(path);

        pathname = get_command_location(parameters[0], head);

        strcpy(parameters[0], pathname);
        execute(parameters);
    }
    return 0;
}