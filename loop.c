#include "main.h"

/**
 * _getline_command - prepares the command line.
 *
 * Return: The command line or NULL if there is an error.
 */
char *_getline_command(void)
{
	char *input = NULL;
	size_t size = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	if (getline(&input, &size, stdin) == -1)
	{
		free(input);
		return (NULL); /* Return NULL in case of error */
	}
	return (input); /* Return the command line */
}
