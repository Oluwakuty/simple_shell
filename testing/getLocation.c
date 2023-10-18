#include "shell.h"

/**
 * envHandle - Function to handle environment variable
 * Return: void
 */

void envHandle(void)
{
	for (char **current = environ; *current; current++)
	{
		write(STDOUT_FILENO, *current, strlen(*current));
		write(STDOUT_FILENO, "\n", 1);
	}
}


/**
 * commandExecution - Function to execute command
 * @args: Character argument
 * @binDirectory: Charcater bin directory
 * @statuse: Status funtion
 * @process_id: calling the child process
 * Return: void
 */

void commandExecution(char *args, char *binDirectory,
		int *statuse, pid_t *process_id)
{
	char fullpath[MAX_CMD_LEN];

	snprintf(fullpath, MAX_CMD_LEN, "%s/%s", binDirectory, args[0]);

	if (access(fullpath, X_OK) != -1)
	{
		*process_id = fork();
		if (*process_id == -1)
		{
			perror("fork");
		}

		if (*process_id == 0)
		{
			execve(fullpath, args, NULL);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(statuse);
		}
	}
}
