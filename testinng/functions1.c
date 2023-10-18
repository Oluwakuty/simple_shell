#include "shell.h"

/**
 * tokenizeUserInput - To tokenize user input
 * @usr_line: Character user line
 * Return: Always Success.
 */

char **tokenizeUserInput(char *usr_line)
{
	char **arr;
	char *tokinz;
	int j = 0;

	arr = malloc(sizeof(char *) * 1024);

	tokinz = strtok(usr_line, " \n");

	do {
		arr[j] = tokinz;

		if (j == 0)
		{
			arr[0] = getLocation(arr[0]);
		}
		tokinz = strtok(NULL, " \n");
		j++;
	} while (tokinz);

	arr[j] = NULL;
	return (arr);
}

/**
 * handleEnvVars - Handles enviornment variables
 * @arr: Pointer to pointer to an array
 * Return: Always success
 */

int handleEnvVars(char **arr)
{
	if (strcmp(arr[0], "setenv") == 0)
	{
		setEnvVar(arr);
		return (1);
	}
	else if (strcmp(arr[0], "unsetenv") == 0)
	{
		unsetEnvVar(arr);
		return (1);
	}
	return (0);
}


/**
 * executeCommand - To execute commad
 * @arr: Pointer to pointer to an array
 * Return: Void
 */

void executeCommand(char **arr)
{
	pid_t child_process_id;
	int statuse;

	/* Fork a child process */
	child_process_id = fork();

	if (child_process_id == -1)
	{
		/* Handle fork error */
		perror("failed to create a child process");
		exit(EXIT_FAILURE);
	}
	if (child_process_id == 0)
	{
		/* Child process execute using execve */
		if (execve(arr[0], arr, NULL) == -1)
		{
			/* Handle execve error */
			perror("execution failed");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process, wait for the child process to complete */
		wait(&statuse);
	}
}
