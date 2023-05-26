#include "main.h"

/**
  * read_line - Read Line
  * Return: Return
  */

char *read_line(void)
{
	char *line = NULL;

	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			if (feof(stdin))
			{
				exit(EXIT_SUCCESS);
			}
		}
		else
		{
			perror("read_line");
			exit(EXIT_FAILURE);
		}
	}

	return (line);
}
