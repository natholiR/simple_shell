#include "main.h"

/**
 * _get_path - to gets the path.
 * @env: Environment variable.
 * Return: Path.
 */

char _get_path(char *env)
{
	size_t new_index = 0, var = 0, length = 5;
	char *path = NULL;

	for (new_index = 0; _strncmp(env[new_index], "PATH=", 5); new_index++)
		;
	if (env[new_index] == NULL)
		return (NULL);

	for (length = 5; env[new_index][var]; var++, length++)
		;
	path = malloc(sizeof(char) * (length + 1));

	if (path == NULL)
		return (NULL);

	for (var = 5, length = 0; env[new_index][var]; var++, length++)
		path[length] = env[new_index][var];

	path[length] = '\0';
	return (path);
}
