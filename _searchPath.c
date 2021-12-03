#include "header.h"

/**
 * _searchPath - Command to write the PATH of an executable
 * @cmds: Double Pointer to commands
 * @buf: Pointer to the buffer
 * @env: Double Pointer to the Environment
 * @argv: Arguments
 * @t: Tally of Errors
 */

void _searchPath(char **cmds, char *buf, char **env, char **argv, int t)
{
	struct stat stat_f;
	char **path;
	int i = 0;

	path = _readdir(cmds[0], env);
	while (path[i])
	{
		if (stat(path[i], &stat_f) == 0)
			execve(path[i], cmds, environ);
		i++;
	}
	_geterrors(argv, cmds[0], t);
	free(buf);
	flush_tok_arr(cmds);
	flush_tok_arr(path);
	exit(EXIT_SUCCESS);
}
