#include "shell.h"

/**
 * custom_tokenizer - tokenizes strings with delimiters
 * @firstLine: POinting to arr received from getline.
 * @delim: Symolizes a terminating point.
 * Return: Pointing to the token.
*/

char *custom_tokenizer(char *firstLine, char *delim)
{
	static char *string;
	char *copyString;
	int f, j;

	if (firstLine != NULL)
		string = firstLine;
	do {
		f = 0, j = 0;
		do {
			if (*string == delim[j])
			{
				f = 1;
				break;
			}
			j++;
		} while (delim[j] != '\0');
		if (!f)
			break;
		string++;
	} while (*string != '\0');
	copyString = string;

	if (*copyString == '\0')
		return (NULL);
	do {
		f = 0, j = 0;

		do {
			if (*string == delim[j])
			{
				*string = '\0';
				string++;
				return (copyString);
			}
			j++;
		} while (delim[j] != '\0');
		if (!f)
			string++;
	} while (*string != '\0');
	return (copyString);
}

/**
 * setEnvVar - To set environment variables
 * @arr: Pointer to pointer to an array
 * Return: Void
 */

void setEnvVar(char **arr)
{
	if (arr[1] == NULL || arr[2] == NULL)
	{
		write(STDERR_FILENO, "setenv: missing arguments\n", 26);
		return;
	}
	if (setenv(arr[1], arr[2], 1) != 0)
	{
		perror("setenv");
	}
}

/**
 * unsetEnvVar - To unset environment variables
 * @arr: Pointer to pointer to an array
 * Return: Void
 */

void unsetEnvVar(char **arr)
{
	if (arr[1] == NULL)
	{
		write(STDERR_FILENO, "unsetenv: missing argument\n", 27);
		return;
	}
	if (unsetenv(arr[1]) != 0)
	{
		perror("unsetenv");
	}
}
