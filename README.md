# Simple Shell by Emmanuel Elisha and Uchechukwu Amua
- This is a simple UNIX shell program written in C
- That reads user input, parses it, and executes it as system commands
- It includes basic shell functionality such as executing commands
- Handling arguments, and managing environment variables

# Getting Started
- To run the program, compile the source code
- Into an executable file using a C compiler such as GCC
- See GCC compiler code below:
- gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
- To start the simple shell, simply run the executable file:
- ./hsh

# Usage
- The simple shell supports the following built-in commands:

- cd: change the current working directory
- env: display the environment variables
- setenv: set a new environment variable or modify an existing one
- unsetenv: remove an environment variable
- alias: allows for the creation of short names for long commands
- exit: for exiting the simple shell

- The simple shell also supports executing system commands and handling arguments

- The simple shell handles the && and || logical operators
- The simple shell handles comments #
- The simple shell handles variables replacement
- The simple shell handles the commands separator;

- Finally, the simple shell can read commands from a file and execute them before exiting

# Acknowledgements
This project was inspired by the Simple Shell Team Project from ALX School
