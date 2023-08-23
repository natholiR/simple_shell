#include "main.h"

/**
* main - Entry point
* @ac: Count of arguments
* @av: Arguments
* @env: Environment variables
* Return: 0 on success
*/
int main(int ac, char **av, char **env)
{
int pathval = 0, stat = 0, is_path = 0;
char *input = NULL, **commands_array = NULL;

(void)ac;

while (1) /*infinite loop*/
{
errno = 0;
input = _getline_command();  /*gets input*/

if (input == NULL && errno == 0)
return (0);

if (input)
{
process_command(input, av, env);
}
else
{
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "\n", 1);
exit(0);
}
}
return (0);
}

void process_command(char *input, char **av, char **env)
{
int stat = 0, is_path = 0;
char **commands_array = NULL;

pathval++;
commands_array = tokenize(input);

if (!commands_array)
{
free(input);
return (0);
}

if (!_strcmp(commands_array[0], "env"))
{
_getenv(env);

}
else
{
is_path = _values_path(&commands_array[0], env);
stat = _fork_fun(commands_array, av, env, input, pathval, is_path);
if (stat == 200)
{
free(input);
free(command_array);
exit(0);
}
if (is_path == 0)
free(commands_array[0]);

free(commands_array);
}

free(input);
}
