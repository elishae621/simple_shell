#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

extern char **environ;

void type_prompt();
void read_command(char *cmd, char **par);
char *get_command_location(char *cmd);
void execute(char *command, char **parameters, char **envp);
char *_getenv(const char *varname);

#endif /* SHELL_H */