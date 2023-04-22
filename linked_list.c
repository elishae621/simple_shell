#include "shell.h"

/**
 * createNode - create a linked list node
 * @directory: directory for this node
 * Return: pointer to created node
 */
linklist *createNode(const char *directory)
{
	linklist *newNode;

	newNode = (linklist *)malloc(sizeof(linklist));

	if (newNode != NULL)
	{
		newNode->directory = strdup(directory);
		newNode->next = NULL;
	}
	return (newNode);
}

/**
 * insertNode - insert a linked list node
 * @head: pointer to head of linked list
 * @directory: directory for this node
 */
void insertNode(linklist **head, const char *directory)
{
	linklist *newNode;
	linklist *current;

	newNode = createNode(directory);

	if (newNode == NULL)
	{
		perror("Error: Failed to allocate memory for new node.\n");
		return;
	}

	if (*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		current = *head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = newNode;
	}
}

/**
 * freeList - free memory of the linked list
 * @head: pointer to head of linked list
 */
void freeList(linklist **head)
{
	linklist *current;
	linklist *next;

	current = *head;
	while (current != NULL)
	{
		next = current->next;
		free(current->directory);
		free(current);
		current = next;
	}
	*head = NULL;
}

/**
 * linkedPath - create linked list of path
 * @path: path
 * Return: pointer to linked list
 */
linklist *linkedPath(char *path)
{
	linklist *head;
	char *pathname;
	char *delim = ":";

	head = createNode("");
	pathname = strtok(path, delim);

	while (pathname)
	{
		insertNode(&head, pathname);
		pathname = strtok(NULL, delim);
	}

	return (head);
}
