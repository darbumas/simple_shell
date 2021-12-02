#include "header.h"
/**
 * const_strlen - String Length, but cannot be below 0
 * @str: Pointer to the string, cannot be altered
 * Return: Returns the non-negative length of the string
 */

unsigned int const_strlen(const char *str)
{
	unsigned int length = 0;

	while (str[length])
		length++;
	return (length);

}
/**
 * _readEnv - Command to print the Environment String
 * @str: Pointer to the string
 * @ev: Double Pointer to the Environment variable
 * Return: Returns the string or NULL
 */

char *_readEnv(const char *str, char **ev)
{
	char *dir, *name;
	unsigned int i = 0, len;

	len = const_strlen(str);
	name = malloc((sizeof(char) * len) + 1);
	if (name == NULL)
		return (NULL);
	_strdup(name, str, len);
	dir = strtok(ev[i], "=");
	while (ev[i])
	{
		if (_strcmp(dir, name))
		{
			dir = strtok(NULL, "\n");
			free(name);
			return (dir);
		}
		i++;
		dir = strtok(ev[i], "=");
	}
	free(name);
	return (NULL);
}
