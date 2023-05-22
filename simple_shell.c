#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>

/**
 * mainPrompt - Main Prompt
 */

#define MAX_COMMAND_LENGTH 100
#define MAX_ERROR_LENGTH (MAX_COMMAND_LENGTH + 30)

void mainPrompt(void)
{
	write(STDOUT_FILENO, "Simple Shell> ", 14);
}

/**
  * executiveCommand - Executive Command
  */
int executeCommand(char *command)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		char errorMessage[MAX_ERROR_LENGTH];
		int length = snprintf(errorMessage, MAX_ERROR_LENGTH, "%s: Fork failed\n", command);
		write(STDERR_FILENO, errorMessage, length);
		_exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		char *args[] = { command, NULL };
		execve(command, args, environ);

		char errorMessage[MAX_ERROR_LENGTH];
		int length = snprintf(errorMessage, MAX_ERROR_LENGTH, "%s: Command execution failed\n", command);
		write(STDERR_FILENO, errorMessage, length);
		_exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}

	return (0);
}

/**
  * main - Main
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
