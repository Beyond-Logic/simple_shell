#include "main.h"

/**
  * main - main
  * Return: Return
  */

int main(void)
{
	char *line;
	char **args;
	int status;

	signal(SIGCHLD, sigchld_handler);
	signal(SIGINT, sigint_handler);

	do {

		printf("Simple Shell> ");
		line = read_line();
		args = split_line(line);
		status = launch(args);

		free(line);
		free(args);
	} while (status);

	return (0);
}
