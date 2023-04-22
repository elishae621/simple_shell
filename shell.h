#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

extern char **environ;

/* Define a struct for the linked list node */
typedef struct linklist
{
	char *directory;
	struct linklist *next;
} linklist;

void type_prompt(void);
void read_command(char **par);
char *get_command_location(char *filename, linklist *head);
char *strconcat(char *first, char *second, char *third);
void execute(char **parameters);
char *_getenv(const char *varname);
linklist *createNode(const char *directory);
void insertNode(linklist **head, const char *directory);
void freeList(linklist **head);
linklist *linkedPath(char *path);

#endif /* SHELL_H */
