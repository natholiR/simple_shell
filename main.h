#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>

extern char **environ;

int _strcmp(char s1, char s2);

int sh_exit(char **args);

int _strlen(char *s);

size_t _strncmp(char s1, char s2, size_t n);

char _strcpy(char dest, char *src);

char _strcat(char dest, char *src);

char _get_path(char *env);

int _putchar(char c);

char *_getline_command(void);

int _values_path(char *arg, char *env);

void _getenv(char **env);

char *tokenize(char lineptr);

int _fork_fun(char *arg, char *av, char *env, char lineptr, int np, int c);

#endif / MAIN_H /
