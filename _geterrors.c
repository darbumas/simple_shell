#include "header.h"
/**
 * write_err - writes error message to standard error stream
 * @err: message in bytes
 * Return: error message
 */

int write_err(char err)
{
	return (write(STDERR_FILENO, &err, 1));
}
/**
 * _geterrors - outputs error message similar to shell
 * @argv: argument vector
 * @cmd_name: commmand entered
 * @tally: count of errors
 */

void _geterrors(char **argv, char *cmd_name, int tally)
{
	int count, d = 1, i = 1;

	count = tally;
	write(STDERR_FILENO, argv[0], _strlen(argv[0]));
	write(STDERR_FILENO, ": ", 2);

	while (count >= 10)
	{
		count /= 10;
		i *= 10;
		d++;
	}
	while (d > 1)
	{
		if ((tally / i) < 10)
			write_err((tally / i + '0'));
		else
			write_err((tally / i) % 10 + '0');
		d--;
		i /= 10;
	}
	write_err(tally % 10 + '0');
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd_name, _strlen(cmd_name));
	write(STDERR_FILENO, ":not found\n", 12);
}
