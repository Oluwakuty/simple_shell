#include "shell.h"

/**
 * ola_print - My custom printf function
 * @mssg: pointer to a constant character
 * Return: Always return zero
 */

void ola_print(const char *mssg)
{
	write(STDOUT_FILENO, mssg, strlen(mssg));
}

/**
 * ola_printOut - My custom printf function
 * @mssg: pointer to a constant character
 * Return: Always return zero
 */

void ola_printOut(const char *mssg, ...)
{
	va_list args;

	char buffer[256];

	va_start(args, mssg);

	vsnprintf(buffer, sizeof(buffer), mssg, args);
	write(STDOUT_FILENO, buffer, strlen(buffer));

	va_end(args);
}
