#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

void type_prompt();
void read_command(char cmd[], char *par[]);
char *get_command_location(char cmd[]);

#endif /* SHELL_H */