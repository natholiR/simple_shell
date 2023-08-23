#include "main.h"

/**
* _strcat - concatenates two strings
*
* @dest: Destination string to append to
* @src: Origin string to append to dest
*
* Return: Pointer to the concatenated string
*/

char *_strcat(char *dest, char *src)
{
int dest_len = 0, src_len = 0;

/* Calculate length of dest string */
while (dest[dest_len] != '\0')
dest_len++;

/* Append src string to dest */
while (src[src_len] != '\0')
{
dest[dest_len] = src[src_len];
dest_len++;
src_len++;
}
dest[dest_len] = '\0';

return (dest);
}

/**
* _strcmp - compares two strings
*
* @s1: First string to compare
* @s2: Second string to compare
*
* Return: The difference between the strings
*/

int _strcmp(char *s1, char *s2)
{
int i = 0;

while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
i++;

return (s1[i] - s2[i]);
}

/**
* _strlen - returns the size of a string
* @s: The string to measure
*
* Return: The size of the string
*/

int _strlen(char *s)
{
int len = 0;

while (s[len] != '\0')
len++;

return (len);
}

/**
* _strncmp - compares two strings up to n bytes
*
* @s1: First string to compare
* @s2: Second string to compare
* @n: Number of bytes to compare
*
* Return: 0 if equal, else the difference
*/

size_t _strncmp(char *s1, char *s2, size_t n)
{
size_t i;

for (i = 0; s1[i] != '\0' && s2[i] != '\0' && i < n; i++)
{
if (s1[i] != s2[i])
return (s1[i] - s2[i]);
}

if (i == n)
return (0);

return (s1[i] - s2[i]);
}

/**
* _strcpy - copies a source string to destination strings
*
* @dest: Destination of the copy
* @src: Source of the copy
*
* Return: Pointer to the destination string
*/

char *_strcpy(char *dest, char *src)
{
int i = 0;

while (src[i] != '\0')
{
dest[i] = src[i];
i++;
}
dest[i] = '\0';

return (dest);
}
