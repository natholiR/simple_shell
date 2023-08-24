#include "main.h"

/**
* tokenize - tokenizes a string
* @lineptr: what the user typed
* Return: a ptr to arr of pointers
*/

char **tokenize(char *lineptr)
{
char **new_array = NULL;
char *token_generator = NULL;
size_t i = 0;
int new_length = 0;

if (lineptr == NULL)
return (NULL);

for (i = 0; lineptr[i]; i++)
{
if (lineptr[i] == ' ')
new_length++;
}
if ((size_t)(new_length + 1) == strlen(lineptr))
return (NULL);
new_array = malloc(sizeof(char *) * (new_length + 2));
if (new_array == NULL)
return (NULL);

token_generator = strtok(lineptr, " \n\t\r");

for (i = 0; token_generator != NULL; i++)
{
new_array[i] = token_generator;
token_generator = strtok(NULL, " \n\t\r");
}
new_array[i] = NULL;
return (new_array);
}

