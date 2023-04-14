#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

void type_prompt();
void read_command(char cmd[], char *par[]);

#endif /* SHELL_H */