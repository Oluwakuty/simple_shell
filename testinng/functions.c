#include "shell.h"

/**
 * env_print - Prints the environment variables
 * @env: Arguments
 */

void env_print(char **env)
{
	int j;

	while (env[j] != NULL)
	{
		ola_printOut("%s\n", env[j]);
		j++;
	}
}

/**
 * forwardSlash - It will check if file starts with "/"
 * @string: The filename to be checked
 * Return: 0 if yes and 1 if NO
 */

int forwardSlash(const char *string)
{
	if (string != NULL && string[0] == '/')
		return (1);
	return (0);
}

/**
 * getLocation - Locate executable path of file
 * @file_name: The executable file
 * Return: Full path to the executable file
 */

char *getLocation(char *file_name)
{
	char *path = "/bin:";
	char *path_copy = NULL, *tokinz, *new_Path = NULL;
	struct stat file_path;

	if (forwardSlash(file_name))
		return (file_name);

	path_copy = strdup(path);

	if (path)
	{
		tokinz = strtok(path_copy, ":");

		while (tokinz)
		{
			char path_buffer[100];

			strcat(path_buffer, tokinz);
			strcat(path_buffer, "/");
			strcat(path_buffer, file_name);
			strcat(path_buffer, "\0");

			if (stat(path_buffer, &file_path) == 0 &&
					access(path_buffer, X_OK) == 0)
			{
				new_Path = strdup(path_buffer);
				break;
			}
			tokinz = strtok(NULL, ":");
		}
		free(path_copy);
	}
	return (new_Path);
}

/**
 * buffer_reading - reads a buffer
 * @formation: File Description
 * @buffs: character buffer to store
 * @sizebuf: size of the bufer
 * Return: Always Success
 */

ssize_t buffer_reading(ino_t formation, char *buffs, ino_t sizebuf)
{
	ssize_t c;

	c = read(formation, buffs, sizebuf - 1);

	if (c >= 0)
	{
		buffs[c] = '\0';
	}
	return (c);
}


/**
 * exit_handling - handle the exit
 * @arr: array type argument
 *
 * Return: Success
 */

void exit_handling(char **arr)
{
	int status;

	/* Checking if the command is exit */
	if (strcmp(arr[0], "exit") == 0)
	{
		/* Checking if there is a 2nd token 'the exit status code' */
		if (arr[1] != NULL)
		{
			/* Converting the 2nd token to an integer & pass to the exit function */
			status = atoi(arr[1]);
			exit(status);
		}
		else
		{
			/* If there is no 2nd token, exit with status code 0 */
			exit(0);
		}
	}
}
