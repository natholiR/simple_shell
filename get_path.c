#include "main.h"
#include <string.h>

/**
 * _get_path - gets the path from the environment variable.
 * @env: Environment variable.
 * Return: Path or NULL if not found or failed to allocate memory.
 */
char *_get_path(char **env)
{
	size_t index = 0;
	char *path = NULL;

	while (env[index] != NULL)
	{

		if (strncmp(env[index], "PATH=", 5) == 0)
		{
			path = malloc(sizeof(char) * (strlen(env[index]) - 4));

			if (path == NULL)
			{
				return (NULL);
				{
				strcpy(path, env[index] + 5);
				return (path);
				}
				index++;
			}
			return (NULL);
		}
