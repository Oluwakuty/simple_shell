#include "main.h"
/**
*get_cmd - function to get the full path
*@command: pointer to the command
*Return: pointer to the full path
*/

char *get_cmd(char *command)
{
	struct stat buf;
	char *full_path;
	char *token;
	char *path;
	/* if the command already path */
	if (stat(command, &buf) == 0)
	{
		return (_strdup(command));
	}
	path = _getenv("PATH");
	/* if there'se no PATH variable in environ*/
	if (!path)
		return (NULL);

	token = strtok(path, ":");
	while (token)
	{
		full_path = malloc(sizeof(char) * (_strlen(token) + _strlen(command) + 2));
		_strcpy(full_path, token);
		_strcat(full_path, "/");
		_strcat(full_path, command);
		if (stat(full_path, &buf) == 0)
		{
			free(path);
			return (full_path);

		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}

