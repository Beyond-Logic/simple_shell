#include "main.h"

/**
  * main - Main
  *
  * Return: Return
  */

int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	int isInteractive = isatty(STDIN_FILENO);

	if (isInteractive)
	{
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
	else
	{
		ssize_t bytesRead = read(STDIN_FILENO, command, MAX_COMMAND_LENGTH);

		if (bytesRead == -1)
		{
			handleInputError(command);
			return (EXIT_FAILURE);
		}
		else if (bytesRead > 0)
		{
			size_t commandLength = bytesRead - 1;

			command[commandLength] = '\0';

			executeCommand(command);
		}
	}

	return (EXIT_SUCCESS);

}
