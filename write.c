#include <unistd.h>
/**
 * write_to_stdout - Write
 *
 * Return: Always 0 (Success)
*/

int write_to_stdout(void)
{
	char message[] = "Hi, C Programming\n";

	int length = sizeof(message) - 1;

	write(STDOUT_FILENO, message, length);

	return (0);
}
