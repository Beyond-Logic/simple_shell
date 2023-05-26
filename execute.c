#include "main.h"

/**
  * execute - execute
  * @args: args
  * Return: Return
  */

int execute(char **args)
{
	pid_t pid;
	int status;

	if (args[0] == NULL)
	{
		return (1);
	}

	pid = fork();

	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror(args[0]);
			exit(EXIT_FAILURE);
		}

		exit(EXIT_SUCCESS);

	}
	else if (pid < 0)
	{
		perror("execute");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}
