#include "shell.h"

/**
 * get_command_location - Get the location of a command
 * @cmd: command
 * Return: location of the command or an empty string if it doesn't exxit
 */
char *get_command_location(char *cmd)
{
    printf("in get location");
    char *location;

    location = malloc(sizeof(char) * (sizeof(cmd) + 10));

    strcpy(location, "");

    /* look for the file in the current directory */
    if (access(cmd, F_OK) != -1)
        strcpy(location, cmd);

    /* look for the bin directory */
    if (access(strcat("/bin/", cmd), F_OK) != -1)
        strcpy(location, (strcat("/bin/", cmd)));

    printf("location: %s", location);

    /* command file doesn't exist */
    return (location);
}