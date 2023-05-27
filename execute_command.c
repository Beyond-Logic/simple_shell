#include "main.h"

/**
  * execute_command - execute command
  * @args: args
  * Return: Return
  */

void execute_command(char **args)
{
	pid_t pid = fork();

	int status;

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
