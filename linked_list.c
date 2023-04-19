#include "shell.h"

// Function to create a new node
linklist *createNode(const char *directory)
{
    linklist *newNode = (linklist *)malloc(sizeof(linklist));
    if (newNode != NULL)
    {
        newNode->directory = strdup(directory); // Duplicate the directory string
        newNode->next = NULL;
    }
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertNode(linklist **head, const char *directory)
{
    linklist *newNode = createNode(directory);
    if (newNode == NULL)
    {
        printf("Error: Failed to allocate memory for new node.\n");
        return;
    }

    if (*head == NULL)
    {
        // If the list is empty, set the new node as the head
        *head = newNode;
    }
    else
    {
        // Traverse to the end of the list and append the new node
        linklist *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to print the linked list
void printList(linklist *head)
{
    printf("Path Directories: ");
    linklist *current = head;
    while (current != NULL)
    {
        printf("%s ", current->directory);
        current = current->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the linked list
void freeList(linklist **head)
{
    linklist *current = *head;
    while (current != NULL)
    {
        linklist *next = current->next;
        free(current->directory); // Free the directory string
        free(current);            // Free the node
        current = next;
    }
    *head = NULL;
}

linklist *linkedpath(char *path)
{
    linklist *head = NULL;
    char *pathname;
    char *delim = ":";

    pathname = strtok(path, delim);

    while (pathname)
    {
        insertNode(&head, pathname);
        pathname = strtok(NULL, delim);
    }
    // Print the linked list
    printList(head);

    return (head);
}
