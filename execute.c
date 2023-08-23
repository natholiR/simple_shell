#include "main.h"

int sh_exit(char **args);

char *builtin_str[] = {"exit"};

int (*builtin_func[])(char **) = {&sh_exit};

/**
 * sh_num_builtins - return the number of builtins.
 * Return: Number of builtins.
 */
int sh_num_builtins(void)
{
    static int num_builtins = sizeof(builtin_str) / sizeof(char *);
    return num_builtins;
}

/**
 * sh_exit - exit the shell.
 * @args: List of arguments.
 * Return: 0 on success, 1 on failure.
 */
int sh_exit(char **args)
{
    return 200;
}

/**
 * _fork_fun - Creates a child process to execute a command.
 * @arg: List of arguments.
 * @av: List of arguments passed to the program.
 * @env: List of environment variables.
 * @lineptr: Pointer to the line buffer.
 * @np: Number of the current process.
 * @c: Flag to check if the command is in the PATH.
 * Return: 0 on success, 1 on failure.
 */
int _fork_fun(char **arg, char **av, char **env, char *lineptr, int np, int c)
{
    pid_t child;
    int stat, i;
    char *format = "%s: %d: %s: not found\n";

    if (arg[0] == NULL)
        return 1;

    int num_builtins = sh_num_builtins();
    for (i = 0; i < num_builtins; i++)
    {
        if (strcmp(arg[0], builtin_str[i]) == 0)
            return builtin_func[i](arg);
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
        return stat;
    }

    return 0;
}
