#include "main.h"

/**
 * main - to Entry point
 * @ac: Count of arguments
 * @av: Arguments
 * @env: the Environment variables
 * Return: 0 on success
 */

int main(int ac, char *av, char *env)
{
	int pathval = 0, stat = 0, is_path = 0;
	char input = NULL, *command_array = NULL;
	(void)ac;
	while (1) /**infinite loop*/
	{
		errno = 0;
		input = _getline_command(); /**gets input*/
		if (input == NULL && errno == 0)
			return (0);
		if (input)
		{
			pathval++, command_array = tokenize(input);
			if (!command_array)
				free(input);
			if (!_strcmp(command_array[0], "env"))
				_getenv(env);
			else
			{
				is_path = _values_path(&command_array[0], env);
				stat = _fork_fun(command_array, av, env, input, pathval, is_path);
				if (stat == 200)
				{
					free(input);
					return (0);
				}
				if (is_path == 0)
					free(command_array[0]);
			}
			free(command_array); /** frees command_array*/
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1); /**prints new line*/
			exit(stat);
		}
		free(input);
	}
	return (0);
}
