#include "main.h"

/**
  * main - Main
  *
  * Return: Return
  */

int main(void)
{
	int isInteractive = isInteractiveMode();

	if (isInteractive)
	{
		processInteractiveInput();
	}

	else
	{
		processNonInteractiveInput();
	}

	return (0);

}
