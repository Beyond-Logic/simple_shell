#include "main.h"
/**
  * executeCommand - Execute Command
  * @command: command
  *
  * Return: Return
  */

int executeCommand(char *command)
{
	char *args[2];
	char errorMessage[MAX_ERROR_LENGTH];
	pid_t childPid;
	int length;

	args[0] = command;
	args[1] = NULL;

	length = snprintf(errorMessage, MAX_ERROR_LENGTH,
				"Error executing command: %s", command);

	if (length < 0 || length >= MAX_ERROR_LENGTH)
	{
		fprintf(stderr, "Failed to construct error message\n");
		_exit(EXIT_FAILURE);
	}

	childPid = fork();

	if (childPid < 0)
	{
		fprintf(stderr, "Failed to fork\n");
		_exit(EXIT_FAILURE);
	}
	else if (childPid == 0)
	{
		execve(command, args, environ);
		fprintf(stderr, "%s\n", errorMessage);
		_exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}

	return (1);
}
