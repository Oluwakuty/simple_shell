#include "shell.h"

/**
 * execution - Carry out the program
 * @command: character
 * @argv: character
 * Return: Success
 */

int execution(char **command, char **argv)
{
	int statuse;
	char **env = environ;
	pid_t valFork;
	char *full_path;

	/* Getting Command Full Path */
	full_path = cmdGetting(command[0]);
	if (!full_path)
	{
		printf("Command unavailable\n");
		spaceFree(command);
		return (127);
	}
	/* Calling Fork */
	valFork = fork();
	if (valFork == -1)
	{
		perror(argv[0]);
		spaceFree(command);
		exit(1);
	}
	if (valFork == 0)
	{
		if (execve(full_path, command, env) == -1)
		{	perror(argv[0]);
			spaceFree(command);
			free(full_path);
			full_path = NULL;
		}
	} else
	{
		waitpid(valFork, &statuse, 0);
		if (statuse == -1)
		{
			perror("Wait error");
		}
		spaceFree(command);
		free(full_path);
	}
	return (statuse);
}


/**
 * spaceFree - Function to free allocated space
 * @freed: character pointer
 */

void spaceFree(char **freed)
{
	int j = 0;

	if (!freed)
		return;

	while (freed[j])
	{
		free(freed[j]);
		freed[j] = NULL;
		j++;
	}
	free(freed);
	freed = NULL;
}
