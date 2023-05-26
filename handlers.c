#include "main.h"

/**
  * sigchld_handler - Sig Chld Handler
  * @sig: sig
  */

void sigchld_handler(int sig)
{
	(void)sig;

	while (waitpid(-1, NULL, WNOHANG) > 0)
	{
	}
}


/**
  * sigint_handler - Sig Int Handler
  * @sig: sig
  */

void sigint_handler(int sig)
{
	(void)sig;

	write(STDOUT_FILENO, "\n$ ", 3);
}
