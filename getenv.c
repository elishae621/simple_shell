#include "shell.h"

char *_getenv(const char *varname)
{

    if (varname == NULL || strlen(varname) == 0)
    {
        return NULL; /* Invalid input */
    }

    for (int i = 0; environ[i] != NULL; i++)
    {
        /* Each environment variable is in the form "VARNAME=VALUE" */
        char *env_var = strdup(environ[i]);
        char *env_var_name = strtok(env_var, "=");

        char *env_value = strtok(NULL, "");

        if (env_value != NULL)
        {
            if (strcmp(env_var_name, varname) == 0)
            {
                return env_value;
            }
        }
    }

    return NULL;
}
