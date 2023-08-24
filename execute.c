#include "main.h"

int sh_exit(char **args);

char *builtin_str[] = {"exit"};

int (*builtin_func[])(char **) = {&sh_exit};

/**
<<<<<<< HEAD
 * sh_num_builtins - return the number of builtins.
=======
 * sh_num_builtins -  a  return the number of builtins.
>>>>>>> dab3f297aaaaa51bb8bd99a377b5df3853ab1e8d
 * Return: Number of builtins.
 */

int sh_num_builtins(void)
{
	return (sizeof(builtin_str) / sizeof(char *));
}

/**
<<<<<<< HEAD
 * sh_exit - exit the shell.
=======
 * sh_exit - a exit the shell.
>>>>>>> dab3f297aaaaa51bb8bd99a377b5df3853ab1e8d
 * @args: List of arguments.
 * Return: 0 on success, 1 on failure.
 */
int sh_exit(char **args)
{
	(void)args;
	free(args);
	return (200);
}

/**
<<<<<<< HEAD
 * _fork_fun - Creates a child process to execute a command.
 * @arg: List of arguments.
 * @av: List of arguments passed to the program.
 * @env: List of environment variables.
 * @lineptr: Pointer to the line buffer.
=======
 * _fork_fun - to Creates a child process to execute a command.
 * @arg: a List of arguments.
 * @av: a List of arguments passed to the program.
 * @env: a List of environment variables.
 * @lineptr: a Pointer to the line buffer.
>>>>>>> dab3f297aaaaa51bb8bd99a377b5df3853ab1e8d
 * @np: Number of the current process.
 * @c: Flag to check if the command is in the PATH.
 * Return: 0 on success, 1 on failure.
 */
<<<<<<< HEAD
=======

>>>>>>> dab3f297aaaaa51bb8bd99a377b5df3853ab1e8d
int _fork_fun(char **arg, char **av, char **env, char *lineptr, int np, int c)
{

	pid_t child;
	int stat, i = 0;
	char *format = "%s: %d: %s: not found\n";

	if (arg[0] == NULL)
		return (1);
	for (i = 0; i < sh_num_builtins(); i++)
	{
<<<<<<< HEAD
		if (_strcmp(arg[0], builtin_str[i]) == 0)
=======
		if (strcmp(arg[0], builtin_str[i]) == 0)
>>>>>>> dab3f297aaaaa51bb8bd99a377b5df3853ab1e8d
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


