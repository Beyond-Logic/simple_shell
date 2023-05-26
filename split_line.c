#include "main.h"

/**
  * split_line - split_line
  * @line: line
  * Return: Return
  */

char **split_line(char *line)
{
	int bufsize = MAX_NUM_ARGS, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token, **tokens_backup;

	if (!tokens)
	{
		fprintf(stderr, "split_line: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \t\r\n\a");

	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += MAX_NUM_ARGS;
			tokens_backup = tokens;
			tokens = realloc(tokens, bufsize * sizeof(char *));

			if (!tokens)
			{
				free(tokens_backup);
				fprintf(stderr, "split_line: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, " \t\r\n\a");
	}
	tokens[position] = NULL;

	return (tokens);

}
