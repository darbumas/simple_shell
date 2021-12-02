#include "header.h"
/**
* _strdup - a ƒ() returns a pointer to a null-terminated string.
* @dest: pointer to a string.
* @src: pointer to a const. string.
* @len: number of characters in 'src'.
* Return: pointer to dest.
*/

char *_strdup(char *dest, const char *src, int len)
{
	int idx;

	for (idx = 0; idx < len && src[idx] != '\0'; idx++)
		dest[idx] = src[idx];

	for ( ; idx < len; idx++)
		dest[idx] = '\0';

	return (dest);
}
