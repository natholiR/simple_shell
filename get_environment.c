#include "main.h"

/**
 * _getenv - prints the environment variables
 *
 * @env: pointer to environment variable array
 */
void _getenv(char **env)
{
    size_t index = 0;

    while (env[index] != NULL)
    {
        char *env_var = env[index];
        size_t env_var_len = _strlen(env_var);
        char *output = malloc(env_var_len + 2); // +2 for the new line and null terminator

        if (output != NULL)
        {
            memcpy(output, env_var, env_var_len);
            output[env_var_len] = '\n';
            output[env_var_len + 1] = '\0';

            write(STDOUT_FILENO, output, env_var_len + 1);

            free(output);
        }

        index++;
    }
}
