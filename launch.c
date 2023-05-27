#include "main.h"

/**
  * launch - launch
  * @args: args
  * Return: Return
  */

int launch(char **args)
{
	pid_t pid;

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
	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		return (1);
	}
	else if (pid == 0)
	{
		execvp(args[0], args);

		perror(args[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
	}
	return (1);
}
