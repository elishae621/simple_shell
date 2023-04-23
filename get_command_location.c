#include "shell.h"

/**
 * strconcat - concats 3 locations in a newly allocated memory
 * @first: first string
 * @second: second string
 * @third: Third string
 * Return: pointer to the new string
 */
char *strconcat(char *first, char *second, char *third)
{
	char *result;
	int len1, len2, len3, i, k;

	len1 = strlen(first);
	len2 = strlen(second);
	len3 = strlen(third);

	result = malloc(sizeof(char) * (len1 + len2 + len3 + 1));

	if (!result)
		return (NULL);

	for (i = 0; first[i]; i++)
		result[i] = first[i];
	k = i;

	for (i = 0; second[i]; i++)
		result[k + i] = second[i];
	k = k + i;

	for (i = 0; third[i]; i++)
		result[k + i] = third[i];
	k = k + i;

	result[k] = '\0';

	return (result);
}

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
