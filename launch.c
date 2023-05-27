#include "main.h"

/**
  * launch - launch
  * @args: args
  * Return: Return
  */

int launch(char **args)
{
	if (args[0] == NULL)
	{
		return (1);
	}

	if (strcmp(args[0], "cd") == 0)
	{
		if (args[1] == NULL)
		{
			fprintf(stderr, "cd: missing argument\n");
		}
		else
		{
			if (chdir(args[1]) != 0)
			{
				perror(args[0]);
			}
		}

		return (1);
	}

	else if (strcmp(args[0], "exit") == 0)
	{
		exit(0);
	}

	return (execute(args));
}
