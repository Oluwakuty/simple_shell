#include "shell.h"


/**
 * writePrompt - To display prompt for user to type
 * Return: void
 */

void writePrompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "(Oluwakuti)$ ", 13);
}


/**
 * _strcpy - String Copier
 * @destination : Array pointer
 * @source : Array pointer
 * Return: Success
 */

char *_strcpy(char *destination, char *source)
{
	int j;

	for (j = 0; source[j]; j++)
	{
		destination[j] = source[j];
	}
	destination[j] = '\0';
	return (destination);
}


/**
 * cmdGetting - Getting full path
 * @command: pointer
 * Return: Success
 */

char *cmdGetting(char *command)
{
	char *path;
	char *tokinz;
	struct stat buff;
	char *full_path;

	/* if the command already path */
	if (stat(command, &buff) == 0)
	{
		return (_strdup(command));
	}
	path = envGetting("PATH");

	/* if there's no PATH variable in environ*/
	if (!path)
		return (NULL);
	tokinz = strtok(path, ":");

	while (tokinz)
	{
		full_path = malloc(sizeof(char) * (_strlen(tokinz) + _strlen(command) + 2));
		_strcpy(full_path, tokinz);
		_strcat(full_path, "/");
		_strcat(full_path, command);

		if (stat(full_path, &buff) == 0)
		{
			free(path);
			return (full_path);
		}
		free(full_path);
		tokinz = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}
