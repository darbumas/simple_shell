#include "header.h"

/**
 * _writeEnv - writes environment variable to standard out
 * @env: pointer to the current environment
 */

void _writeEnv(char **env)
{
	unsigned int i = 0, p_len;

	while (env[i])
	{
		p_len = _strlen(env[i]);
		write(STDOUT_FILENO, env[i], p_len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

/**
 * _printEnv - Command to Print the Current Working Environment
 * @buf: Pointer to the buffer
 * @tok: Double pointer to the token
 * @env: Double Pointer to the current environment
 */

void _printEnv(char *buf, char **tok, char **env)
{
	free(buf);
	flush_tok_arr(tok);
	_writeEnv(env);
	exit(EXIT_SUCCESS);
}
