#include "main.h"

/**
* _values_path - Concatenates the command with the path.
* @arg: Argument.
* @env: Environment.
* Return: 0 if success, -1 otherwise.
*/
int _values_path(char **arg, char **env)
{
char *new_token = NULL, *relative_path = NULL, *absolute_path = NULL;
size_t value_path, length;
struct stat lineptr_status;

/**
* Check if the argument exists
*/
if (stat(*arg, &lineptr_status) == 0)
return (-1);

/**
* Get the relative path
*/
relative_path = _get_path(env);
if (!relative_path)
return (-1);

/**
* Tokenize the path
*/
new_token = strtok(relative_path, ":");

/**
* Get the length of the argument
*/
length = strlen(*arg);

/**
* Loop through each tokenized path
*/
while (new_token)
{
value_path = strlen(new_token);

/**
* Allocate memory for the absolute path
*/
absolute_path = malloc(sizeof(char) * (value_path + length + 2));
if (!absolute_path)
{
free(relative_path);
return (-1);
}

/**
* Copy the tokenized path and concatenate the argument
*/
absolute_path = strcpy(absolute_path, new_token);
strcat(absolute_path, "/");
strcat(absolute_path, *arg);

/**
*
* Check if the absolute path exists
*/
if (stat(absolute_path, &lineptr_status) == 0)
{
*arg = absolute_path;
free(relative_path);
return (0);
}

/**
* Free the absolute path memory
*/
free(absolute_path);

/**
* Get the next tokenized path
*/
new_token = strtok(NULL, ":");
}

/**
* Free the relative path memory
*/
free(relative_path);

/**
* Return -1 if the absolute path does not exist
*/
return (-1);
}
