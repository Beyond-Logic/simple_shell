#include "main.h"

/**
  * launch - launch
  * @args: args
  * Return: Return
  */

int launch(char **args)
{
	int i;

	char *builtins[] = {
		"cd",
		"exit",
		NULL
	};

	if (args[0] == NULL)
	{
		return (1);
	}

	for (i = 0; builtins[i]; i++)
	{
		if (strcmp(args[0], builtins[i]) == 0)
		{
			if (strcmp(args[0], "exit") == 0)
			{
				exit(0);
			}
			return (1);
		}
	}

	return (execute(args));
}
