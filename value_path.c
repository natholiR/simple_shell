#include "main.h"

/**
* _values_path - A Concatenates the command with the path.
* @arg: Argument.
* @env: Environment.
* Return: 0 if success.
*/
int _values_path(char *arg, char *env)
{
char new_token = NULL, relat_path = NULL, *absolute_path = NULL;
size_t value_path, length;
struct stat lineptr_status;
if (stat(*arg, &lineptr_status) == 0)
return (-1);
relat_path = _get_path(env); /**gets the path*/
if (!relat_path)
return (-1);
new_token = strtok(relative_path, ":"); /**tokenizes a  path*/
length = strlen(*arg);                 /**gets the length of a  argument*/
while (new_token)
{
value_path = strlen(new_token);
absolute_path = malloc(sizeof(char) * (value_path + length + 2));
if (!absolute_path)
{
free(relat_path);
return (-1);
}
absolute_path = strcpy(absolute_path, new_token);
strcat(absolute_path, "/");
strcat(absolute_path, *arg);

if (stat(absolute_path, &lineptr_status) == 0)
{
*arg = absolute_path;
free(relat_path);
return (0);
}
free(absolute_path);
new_token = strtok(NULL, ":");
}
new_token = '\0';
free(relat_path);
{
return (-1);
}
}
