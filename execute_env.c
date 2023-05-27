#include "main.h"

/**
  * execute_env - execute env
  * Return: Return
  */

void execute_env(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
