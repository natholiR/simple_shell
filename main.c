#include "main.h"

/**
 * executeCommand - Execute built-in commands
 * @command: The command string to execute
 * @env: Environment variables
 *
 * Return: 1 if the command is handled, 0 otherwise
 */
int executeCommand(char **command, char **env)
{
	if (command == NULL || command[0] == NULL)
		return (0);

	if (_strcmp(command[0], "cd") == 0)
	{
		/* Handle 'cd' command */
		if (command[1] == NULL)
		{
			printf("Invalid usage of 'cd' command.\n");
		}
		else
		{
			if (chdir(command[1]) == -1)
			{
				printf("Directory change failed.\n");
			}
		}
		return (1); /* Indicate that the command was handled */
	}
	else if (_strcmp(command[0], "exit") == 0)
	{
		/* Handle 'exit' command */
		printf("Exiting the shell.\n");
		exit(0);
	}
	else if (_strcmp(command[0], "env") == 0)
	{
		/* Handle 'env' command */
		_getenv(env);
		return (1); /* Indicate that the command was handled */
	}

	return (0); /* Indicate that the command was not handled */
}

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
			if (executeCommand(commands_array, env))
			{
				free(commands_array);
				continue;
			}
			is_path = _values_path(&commands_array[0], env);
			stat = _fork_fun(commands_array, av, env, input, pathval, is_path);
			if (stat == 200)
			{
				free(input);
				return (0);
			}
			if (is_path == 0)
				free(commands_array[0]);

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
