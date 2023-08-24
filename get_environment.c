#include "main.h"

/**
 * _getenv - To prints the environment
 *
 * @env: environment variable to print
 *
 */

void _getenv(char **env)
{
	size_t runn = 0;

	while (env[runn])
	{
		write(STDOUT_FILENO, env[runn], _strlen(env[runn]));
		write(STDOUT_FILENO, "\n", 1);
		runn++;
	}
}
