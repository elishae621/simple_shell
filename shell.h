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

void type_prompt();
void read_command(char *cmd, char **par);
char *get_command_location(char *filename, linklist *head);
void execute(char *command, char **parameters, char **envp);
char *_getenv(const char *varname);
linklist *createNode(const char *directory);
void insertNode(linklist **head, const char *directory);
void printList(linklist *head);
void freeList(linklist **head);
linklist *linkedpath(char *path);

#endif /* SHELL_H */