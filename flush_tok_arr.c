#include "header.h"

/**
 * flush_tok_arr - command to flush the array of tokens
 * @ptr: Double Pointer to the command array
 */

void flush_tok_arr(char **ptr)
{
	unsigned int i = 0;

	if (ptr == NULL)
		return;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	if (ptr[i] == NULL)
		free(ptr[i]);
	free(ptr);
}

/**
 * _flush_parent - command to flush the parent of tokens
 * @buffer: Pointer to the buffer
 * @cmds: Double Pointer to the tokenized commands
 */

void _flush_parent(char *buffer, char **cmds)
{
	free(buffer);
	flush_tok_arr(cmds);
}
