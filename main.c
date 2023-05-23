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
				char errorMessage[MAX_ERROR_LENGTH];

				int length = sprintf(errorMessage, MAX_ERROR, LENGTH, "%s: Error reading input\n", command);

				write(STDERR_FILENO, errorMessage, length);
				_exit(EXIT_FAILURE);
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
			char errorMessage[MAX_ERROR_LENGTH];
			int length = snprintf(errorMessage, MAX_ERROR_LENGTH, "%s: Error reading input\n", command);

			write(STDERR_FILENO, errorMessage, length);
			_exit(EXIT_FAILURE);
		}
		else if (bytesRead > 0)
		{
			size_t commandLength = bytesRead - 1;

			command[commandLength] = '\0';

			executeCommand(command);
		}
	}

	return (0);

}
