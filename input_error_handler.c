#include "main.h"

/**
  * handleInputError - Hanlde Input Error
  * @command: command
  */

void handleInputError(char *command)
{
	char errorMessage[MAX_ERROR_LENGTH];
	int length = snprintf(errorMessage, MAX_ERROR_LENGTH,
			"%s: Error reading input\n", command);

	write(STDERR_FILENO, errorMessage, length);
	_exit(EXIT_FAILURE);
}
