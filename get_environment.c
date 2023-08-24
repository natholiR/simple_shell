#include "main.h"

/**
 * _getenv - prints the environment
 *
 * @env: environment variable to print
 *
 */

void _getenv(char **env)
{
	size_t runner = 0;

	while (env[runner])
	{
		write(STDOUT_FILENO, env[runner], _strlen(env[runner]));
		write(STDOUT_FILENO, "\n", 1);
		runner++;
	}
}
