#include "main.h"

/**
* _getline_command - prompt to take the command line
*
* Return: the command line
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
return (NULL);
}

return (input);
}



