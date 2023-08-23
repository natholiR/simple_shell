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
/**
 * check if lineptr is NULL
 */
if (lineptr == NULL)
return NULL;

/**
 * count number of tokens in lineptr
 *
 */
for (i = 0; lineptr[i] != '\0'; i++)
{
if (lineptr[i] == ' ')
new_length++;
}

/**
 * allocate memory for new_array
 *
 */
new_array = malloc(sizeof(char *) * (new_length + 2));
if (new_array == NULL)
return NULL;

/**
 * tokenize lineptr and store tokens in new_array
 */
token_generator = strtok(lineptr, " \n\t\r");
for (i = 0; token_generator != NULL; i++)
{
size_t token_length = strlen(token_generator);
new_array[i] = malloc(sizeof(char) * (token_length + 1));
if (new_array[i] == NULL)
{
/**
 *  free previously allocated memory
 */
for (size_t j = 0; j < i; j++)
free(new_array[j]);
free(new_array);
return NULL;
}
strcpy(new_array[i], token_generator);
token_generator = strtok(NULL, " \n\t\r");
}
new_array[i] = NULL; 
/*
 *  set last element of new_array to NULL
 */

return new_array;
}
