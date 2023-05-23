#include "main.h"

/**
  * executeCommand - Execute Command
  * @command: command
  *
  * Return: Return
  */

int executeCommand(char *command)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		char errorMessage[MAX_ERROR_LENGTH];
		int length = snprintf(errorMessage, MAX_ERROR_LENGTH,
				"%s: Fork failed\n", command);

		write(STDERR_FILENO, errorMessage, length);

		_exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		char *args[] = { command, NULL };

		execve(command, args, environ);

		char errorMessage[MAX_ERROR_LENGTH];

		int length = snprintf(errorMessage, MAX_ERROR_LENGTH,
				"%s: Command execution failed\n", command);

		write(STDERR_FILENO, errorMessage, length);
		_exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}

	return (0);
}
