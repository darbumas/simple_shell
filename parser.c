#include "header.h"
/**
 * cmd_count - returns count of strings separated by a space char.
 * @str: pointer to a string in buffer
 * Return: count of strings.
 */

unsigned int cmd_count(char *str)
{
	unsigned int sp = 0, i = 0, count = 0;

	while (str[i] != '\0')
	{
		if (str[i] != ' ')
			sp = 1;
		if ((sp && str[i + 1] == ' ') || (sp && str[i + 1] == '\0'))
		{
			count++;
			sp = 0;
		}
		i++;
	}
	return (count);
}
/**
 * _getCmdTok - returns a double pointer to a string in allocated memory.
 * @str: pointer to string in buffer.
 * Return: list of commands
 */
char **_getCmdTok(char *str)
{
	char **tokens, *tok;
	unsigned int count;
	int i = 0;

	str[_strlen(str) - 1] = '\0';
	count = cmd_count(str);
	if (count == 0)
		return (NULL);

	tokens = malloc((sizeof(char *)) * (count + 1));

	if (tokens == NULL)
		return (NULL);
	tok = strtok(str, " ");
	while (tok != NULL)
	{
		tokens[i] = malloc(_strlen(tok) + 1);
		if (tokens[i] == NULL)
		{
			flush_tok_arr(tokens);
			return (NULL);
		}
		_strncpy(tokens[i], tok, _strlen(tok) + 1);
		tok = strtok(NULL, " ");
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
