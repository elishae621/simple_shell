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

/**
 * struct linklist - linked list of all path variables
 * @directory: pointer to directory string
 * @next: pointer to next node
 */
typedef struct linklist
{
	char *directory;
	struct linklist *next;
} linklist;

/**
 * struct funcTable - table of name and function pointer
 * @name: name of builtin command
 * @func: pointer to builtin command
 */
typedef struct funcTable
{
	char *name;
	void (*func)(char **);
} funcTable;

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
void sig_handler(int sig_num);
void (*getBuiltin(char **parameters))(char **parameters);
void myexit(char **parameters);
void myenv(char **parameters __attribute__((unused)));
void _puts(char *string);

#endif /* SHELL_H */
