#include "main.h"

/**
  * printPrompt - Print Prompt
  *
  */

void printPrompt(void)
{
	write(STDOUT_FILENO, "Simple Shell> ", 14);
}

/**
  * isInteractiveMode - Is Interactive Mode
  *
  */

void isInteractiveMode(void)
{
	return (isatty(STDIN_FILENO));
}

/**
  * processInteractiveInput - Process Interactive Input
  *
  */

void processInteractiveInput(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		printPrompt();

		ssize_t bytesRead = read(STDIN_FILENO, command, MAX_COMMAND_LENGTH);

		if (bytesRead == -1)
		{
			handleInputError(command);
			break;
		}

		else if (bytesRead == 0)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}

		size_t commandLength = bytesRead - 1;

		command[commandLength] = '\0';

		if (commandLength == 0)
		{
			continue;
		}

		executeCommand(command);
	}
}
