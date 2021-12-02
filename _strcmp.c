#include "header.h"
/**
* _strcmp - a f() that compares two strings.
* @str1: pointer to string.
* @str2: pointer to string.
* Return: 1 if strings are copies, 0 if different.
*/

int _strcmp(char *str1, char *str2)
{
	unsigned int i = 0;

	while (str1[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}
