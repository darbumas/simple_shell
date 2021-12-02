#include "header.h"

/**
 * _sighandler - command to provide for interrupt signals
 * @feed: Signal to send to the shell processes
 */

void _sighandler(int feed)
{
	(void)feed;
	write(STDOUT_FILENO, "\n$ ", 3);
}
