#include "shell.h"

/**
 * get_command_location - Get the location of a command
 * @cmd: command
 * Return: location of the command or an empty string if it doesn't exxit
 */
char *get_command_location(char cmd[])
{
    char location[100];

    /* look for the file in the current directory */
    if (access(cmd, F_OK) != -1)
        return (cmd);

    /* look for the bin directory */
    if (access(strcat("/bin/", cmd), F_OK) != -1)
        return (strcat("/bin/", cmd));

    /* command file doesn't exist */
    return ("");
}