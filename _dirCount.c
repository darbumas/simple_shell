#include "header.h"

/**
 * _dirCount - Command to count the number of directories of a file
 * @p: Pointer to the PATH string
 * Return: number of components in the PATH
 */

unsigned int _dirCount(char *p)
{
	unsigned int count = 0, dir = 0, i = 0;

	while (p[i])
	{
		if (p[i] != ':')
			dir = 1;
		if ((dir && p[i + 1] == ':') || (dir && p[i + 1] == '\0'))
		{
			count++;
			dir = 0;
		}
		i++;
	}
	return (count);
}
