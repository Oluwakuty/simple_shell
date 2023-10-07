#include <unistd.h>

/**
 * main - The main code
 *
 * Return: Always success
 */

int main(void)
{
	char birthday[] = "Hello Julien, you are 50 years of age!\n";
	ssize_t letter = sizeof(birthday) - 1;

	if (write(1, birthday, letter) != letter)
	{
		write(2, "Error writing to stdout\n", 24);
		return (1);
	}
	return (0);
}
