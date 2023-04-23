#include "shell.h"

/**
 * get_command_location - Get the location of a command from path
 * @filename: command
 * @head: linked list of path variables
 * Return: location of the command or NULL if it doesn't exxit
 */
char *get_command_location(char *filename, linklist *head)
{
	char *location;
	linklist *tmp;

	tmp = head;
	while (tmp)
	{

		location = strconcat(tmp->directory, "/", filename);

		if (access(location, F_OK) == 0)
		{
			return (location);
		}
		free(location);
		tmp = tmp->next;
	}
	return (NULL);
}
