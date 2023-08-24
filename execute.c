#include "main.h"

int sh_exit(char **args);

char *builtin_str[] = {"exit"};

int (builtin_func[])(char *) = {&sh_exit};

/**
* sh_num_builtins - To return the number of builtins.
* Return: A Number of builtins.
*/

int sh_num_builtins(void)
{
return (sizeof(builtin_str) / sizeof(char *));
}

/**
* sh_exit - To exit the shell.
* @args: List of the arguments.
* Return: 0 on success, 1 on failure.
*/
int sh_exit(char **args)
{
(void)args;
free(args);
return (200);
}

/**
* _fork_fun - Creates the child process to execute a command.
* @arg: List of the arguments.
* @av: List of arguments passed to the program.
* @env: List of the environment variables.
* @lineptr: A Pointer to the line buffer.
* @np: the Number of the current process.
* @c: Flag to check if the command is in the PATH.
* Return: 0 on success, 1 on failure.
*/
int _fork_fun(char *arg, char *av, char *env, char lineptr, int np, int c)
{

pid_t child;
int stat, i = 0;
char *format = "%s: %d: %s: not found\n";

if (arg[0] == NULL)
return (1);
for (i = 0; i < sh_num_builtins(); i++)
{
if (_strcmp(arg[0], builtin_str[i]) == 0)
return (builtin_func[i](arg));
}
child = fork();
if (child == 0)
{
if (execve(arg[0], arg, env) == -1)
{
fprintf(stderr, format, av[0], np, arg[0]);
if (!c)
free(arg[0]);
free(arg);
free(lineptr);
exit(errno);
}
}
else
{
wait(&stat);
return (stat);
}
return (0);
}
