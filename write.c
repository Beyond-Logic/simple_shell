#include <unistd.h>
/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
*/

int main(void)
{
	char message[] = "Hi, C Programming\n";

	int length = sizeof(message) - 1;

	write(STDOUT_FILENO, message, length);

	return (0);
}
