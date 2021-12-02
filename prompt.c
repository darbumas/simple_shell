#include "header.h"
/**
 * prompt - command to bring up the prompt
 * Return: Returns 0 for success.
 */

int prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "($) ", 4);
	return (0);
}
