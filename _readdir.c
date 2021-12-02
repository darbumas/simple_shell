#include "header.h"
/**
 * _catEnvVar - concatenates commands entered
 * @dest: Destination String
 * @src: Source String
 * @cmd: Command to be concatenated
 * @dest_len: Length of the resultant string
 * @cmd_len: Length of the new command
 * Return: The string of the resultant command
 */

char *_catEnvVar(char *dest, char *src, char *cmd, int dest_len, int cmd_len)
{
	int i, j;

	for (i = 0; i < dest_len && src[i] != '0'; i++)
		dest[i] = src[i];
	dest[i] = '/';
	i++;
	for (j = 0; j < cmd_len && cmd[j] != '\0'; j++, i++)
		dest[i] = cmd[j];
	dest[i] = '\0';
	return (dest);
}
/**
 * _readdir - Command to create an array to contain the PATH
 * @cmd_name: Pointer to store the name of the command specified
 * @env: Double Pointer to store the current Environment
 * Return: Either the Directory Heap or NULL
 */

char **_readdir(char *cmd_name, char **env)
{
	char **de, *_env, *_dir;
	unsigned int i = 0, len;
	int count, cmd;

	_env = _readEnv("PATH", env);
	len = _dirCount(_env);
	de = malloc(sizeof(char *) * (len + 1));
	if (de == NULL)
		return (NULL);

	_dir = strtok(_env, ":");
	while (_dir != NULL)
	{
		count = _strlen(_dir);
		cmd = _strlen(cmd_name);
		de[i] = malloc(sizeof(char) * (count + cmd + 2));
		if (de[i] == NULL)
		{
			flush_tok_arr(de);
			return (NULL);
		}
		_catEnvVar(de[i], _dir, cmd_name, count, cmd);
		i++;
		_dir = strtok(NULL, ":");
	}
	de[i] = NULL;
	return (de);
}
