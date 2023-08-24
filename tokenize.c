#include "main.h"

/**
* tokenize - To tokenizes a string
* @lineptr: what a user typed
* Return: the ptr to arr of pointers
*/

char *tokenize(char lineptr)
{
char **new_array = NULL;
char *token_generator = NULL;
size_t i = 0;
int length = 0;

if (lineptr == NULL)
return (NULL);

for (i = 0; lineptr[i]; i++)
{
if (lineptr[i] == ' ')
length++;
}
if ((size_t)(length + 1) == strlen(lineptr))
return (NULL);
new_array = malloc(sizeof(char)  (length + 2));
if (new_array == NULL)
return (NULL);

tok_generator = strtok(lineptr, " \n\t\r");

for (i = 0; tok_generator != NULL; i++)
{
new_array[i] = tok_generator;
tok_generator = strtok(NULL, " \n\t\r");
}
new_array[i] = NULL;
return (new_array);
}
