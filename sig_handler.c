#include "shell.h"

/**
 * sig_handler - handle if control + C is pressed
 * @sig_num: int
 */
void sig_handler(int sig_num)
{
    if (sig_num == SIGINT)
    {
        write(STDOUT_FILENO, "\n", 2);
        type_prompt();
    }
}
