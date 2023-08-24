#include "main.h"

/**
 * _strcat -To concatenates two strings
 *
 * @dest: A Destination string
 *
 * @src: Origin string or source
 * Return: concatenated string
 */

char _strcat(char dest, char *src)
{
	int o, k = 0;

	for (o = 0; dest[o] != '\0'; o++)
	{
	}
	for (k = 0; src[k] != '\0'; k++)
	{
		dest[o] = src[k];
		o++;
	}
	dest[o] = '\0';
	return (dest);
}

/**
 * _strcmp - compares two strings
 *
 * @s1: a string
 * @s2: Another string
 *
 * Return: the difference between the strings
 *
 */

int _strcmp(char s1, char s2)
{
	int k = 0;
	int val;

	while (s1[k] != 0 && s2[k] != 0 && s1[k] == s2[k])
		k++;
	val = s1[k] - s2[k];
	return (val);
}

/**
 * _strlen - returns the size of the string
 * @s: the string to measure
 * Return: the size of the string
 */

int _strlen(char *s)
{
	int j;

	for (j = 0; s[j] != 0; j++)
		;

	return (j);
}

/**
 *_strncmp -  To compares two strings
 *@s1: A string one
 *@s2: A string two
 *@n: A number of bytes
 * Return: 0 if equal, else the difference
 */

size_t _strncmp(char s1, char s2, size_t n)
{
	size_t k, l;

	for (l = 0; s1[l] != '\0' && l < n; l++)
	{
		k = s1[l] - s2[l];

		if (k != 0)
		{
			return (k);
		}
	}
	return (0);
}

/**
 * _strcpy - copies a  source string to destination strings
 * @dest: destination of the copy
 * @src: source of the copy
 *
 * Return: the pointer to dest
 */

char _strcpy(char dest, char *src)
{
	int j = 0;

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[j] = src[j];
	}
	dest[j + 1] = 0;
	return (dest);
}
