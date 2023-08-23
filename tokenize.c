#include "main.h"

/**
* tokenize - tokenizes a string
* @lineptr: pointer to the string to be tokenized
* Return: pointer to an array of pointers
*/
char **tokenize(char *lineptr)
{
char **new_array = NULL;
char *token_generator = NULL;
size_t i = 0;
int new_length = 0;
if (lineptr == NULL)
return (NULL);

for (i = 0; lineptr[i] != '\0'; i++)
{
if (lineptr[i] == ' ')
new_length++;
}

new_array = malloc(sizeof(char *) * (new_length + 2));
if (new_array == NULL)
return (NULL);

token_generator = strtok(lineptr, " \n\t\r");
for (i = 0; token_generator != NULL; i++)
{
size_t token_length = strlen(token_generator);
new_array[i] = malloc(sizeof(char) * (token_length + 1));
if (new_array[i] == NULL)
{
free(new_array);
return (NULL);
}
strcpy(new_array[i], token_generator);
token_generator = strtok(NULL, " \n\t\r");
}
new_array[i] = NULL;

return (new_array);
}
