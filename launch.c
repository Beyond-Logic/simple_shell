#include "main.h"

/**
  * launch - launch
  * @args: args
  * Return: Return
  */

int launch(char **args)
{

	if (args[0] == NULL)
	{
		return (1);
	}
	else if (strcmp(args[0], "cd") == 0)
	{
		execute_cd(args);
	}
	else if (strcmp(args[0], "exit") == 0)
	{
		execute_exit();
	}
	else if (strcmp(args[0], "env") == 0)
	{
		execute_env();
	}
	else
	{
		execute_command(args);
	}

	return (1);
}
