#include "header.h"
/**
*_strlen - a ƒ() that returns a count of characters in a string.
*@str: pointer to a null terminated string.
*Return: length of string.
*/

unsigned int _strlen(char *str)
{
	unsigned int len = 0;

	while (str[len] != '\0')
		len++;
	return (len);
}
