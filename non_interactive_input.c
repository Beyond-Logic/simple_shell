#include "main.h"

/**
  * processNonInteractiveInput - Process Non Interactive Input
  *
  */

void processNonInteractiveInput(void)
{
	char command[MAX_COMMAND_LENGTH];

	ssize_t bytesRead = read(STDIN_FILENO, command, MAX_COMMAND_LENGTH);

	if (bytesRead == -1)
	{
		handleInputError(command);

		exit(EXIT_FAILURE);
	}
	else if (bytesRead > 0)
	{
		size_t commandLength = bytesRead - 1;

		command[commandLength] = '\0';

		executeCommand(command);
	}
}
