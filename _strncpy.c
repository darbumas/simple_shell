#include "header.h"
/**
*_strncpy - a ƒ() that copies a null terminated string.
*@dest: pointer to a null terminated string (original)
*@src: pointer to a null terminated string (copy).
*@n: count of bytes to be used from src.
*Return: pointer to string terminated string (dest).
*/

char *_strncpy(char *dest, char *src, int n)
{
	int d, i;

	d = i = 0;

	while (src[i] && i < n)
		dest[d++] = src[i++];

	while (d < n)
		dest[d++] = '\0';

	return (dest);
}
