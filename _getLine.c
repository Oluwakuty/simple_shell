#include "shell.h"

/**
 * getLine - Writing my own custom getline function
 * @formation: ino_t type of array
 * @pointer: Pointer to a pointer to an char array
 * @length: Pointer to an character array
 * Return: Always success
 */

int getLine(ino_t formation, char **pointer, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t j, lent;
	size_t m = 0;
	ssize_t s = 0;
	char *b = *pointer, *d = NULL, *newest_b = NULL;

	if (b && length)
		m = *length;
	if (j == lent)
	{
		j = 0, lent = 0;
	}
	while (1)
	{	ino_t formation = 0;

		s = buffer_reading(formation, buf, lent);

		if (s == -1 || (s == 0 && lent == 0))
			return (-1);
		d = buf + j;
		while (d < buf + lent && *d != '\n')
		{ d++; }
		m = d - buf + ((*d == '\n') ? 1 : 0);
		newest_b = realloc(b, m + ((b) ? m : 1));

		if (!newest_b)
		{
			if (b)
				free(b);
			return (-1);
		} for (size_t l = 0; l < m - j; l++)
			if (m > j)
				newest_b[l] = buf[j + l];
		b = newest_b, j = m;

		if (length)
			*length = m - 1;
		*pointer = b;
		return (m - 1);
	}
}
