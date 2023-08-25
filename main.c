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
	while (1) /**infinite loop*/
	{
		errno = 0;
		input = _getline_command(); /**gets input*/
		if (input == NULL && errno == 0)
			return (0);

		if (input)
		{
			pathval++, commands_array = tokenize(input);
			if (!commands_array)
				free(input);
			if (!_strcmp(commands_array[0], "env"))
				_getenv(env);
			else
			{
				is_path = _values_path(&commands_array[0], env);
				stat = _fork_fun(commands_array, av, env, input, pathval, is_path);
				if (stat == 200)
				{
					free(input);
					return (0);
				}
				if (is_path == 0)
					free(commands_array[0]);
			}
			free(commands_array); /** frees commands_array*/
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

