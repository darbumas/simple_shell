#include "header.h"
/**
 * _getnewline - Command to write a new line
 * @buffer: pointer to the buffer
 */

void _getnewline(char *buffer)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(buffer);
	exit(0);
}
