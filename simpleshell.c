#include "shell.h"
/**
 * _strcmp - function that compares two strings
 * @s1: s1
 * @s2: s2
 *
 * Return: 1 if strings re the same, 0 if not
 */
int _strcmp(char *s1, char *s2)
{
	unsigned int i = 0;

	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

/**
 * _strlen - function that finds the length of the string
 * @s the input string
 *
 * Return: The length of the string
 */
unsigned int _strlen(char *s)
{
	unsigned int len = 0;

	while (s[len])
		len++;

	return (len);
}

/**
 * _strcpy - function that copies a string to another string
 * @dest: The pointer to the copied string
 * @src: the pointer to the string to copy for
 *
 * Return: a pointer to copied string
 */
char *_strcpy(char *dest, char *src)
{
	char *aux = dest;

	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (aux);
}

/**
 * _strcat - function that concatenates two strings
 * @dest: an input string
 * @src: an input string
 *
 * Return: a pointer to the resulting string
 */
char *_strcat(char *dest, char *src)
{
	char *temp = dest;

	while (*dest)
		dest++;

	*dest++ = '/';
	while (*src)
		*dest++ = *src++;
	return (temp);
}

/**
 * _atoi - function that converts string to integer
 * @s: an input string
 *
 * Return: integer from conversion.
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int total = 0;
	char null_flag = 0;

	if (s == NULL)
		return (0);
	while (*s)
	{
		if (*s == '-')
			sign *= -1;
		if (*s >= '0' && *s <= '9')
		{
			null_flag = 1;
			total = total * 10 + (*s - '0');
		}
		else if (*s < '0' || *s > '9')
		{
			if (null_flag == 1)
				break;
		}
		s++;
	}
	if (sign < 0)
		total = (-1 * (total));
	return (total);
}

