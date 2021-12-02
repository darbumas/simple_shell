#include "header.h"
/**
 * main - main().
 * @argc: argument count.
 * @argv: argument vector.
 * @env: environment variables.
 * Return: 0 with no problems, 1 with failures.
 */
int main(int argc, char **argv, char **env)
{
	struct stat stat_buf;
	pid_t pid;
	char **cmds;
	char *buffer = NULL, *builtin1 = "exit", *builtin2 = "env";
	int status, tally = 0;
	ssize_t line;
	size_t len = 0;
	(void)argc;

	prompt();
	signal(SIGINT, _sighandler);
	while ((line = getline(&buffer, &len, stdin)))
	{
		if (line == EOF)
			_getnewline(buffer);
		tally++;
		cmds = _getCmdTok(buffer);
		pid = fork();
		if (pid == -1)
			_perror();
		if (pid == 0)
		{
			if (cmds == NULL)
				_flush_buf(buffer);
			else if (_strcmp(builtin1, cmds[0]))
				_flush_abort(buffer, cmds);
			else if (_strcmp(builtin2, cmds[0]))
				_printEnv(buffer, cmds, env);
			else if (stat(cmds[0], &stat_buf) == 0)
				execve(cmds[0], cmds, NULL);
			else
				_searchPath(cmds, buffer, env, argv, tally);
		}
		else
		{
			wait(&status);
			if (cmds == NULL)
				_flush_parent(buffer, cmds);
			else if (_strcmp(builtin1, cmds[0]))
				_flush_abort(buffer, cmds);
			else
				_flush_parent(buffer, cmds);
		}
		len = 0;
		buffer = NULL;
		prompt();
	}
	if (line == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
