#include "header.h"
/**
 * _perror - ƒ() to handle fork() in case it fails
 */

void _perror(void)
{
	perror("ERROR:");
	exit(EXIT_FAILURE);
}

/**
 * _flush_abort - Command to abort a command
 * @buffer: Pointer to the buffer
 * @cmds: Double Pointer to the command being aborted
 */

void _flush_abort(char *buffer, char **cmds)
{
	free(buffer);
	flush_tok_arr(cmds);
	exit(EXIT_SUCCESS);
}

/**
 * _flush_buf - command to flush the buffer
 * @buffer: Pointer to the buffer
 */

void _flush_buf(char *buffer)
{
	free(buffer);
	exit(EXIT_SUCCESS);
}
