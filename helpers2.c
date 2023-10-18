#include "main.h"

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
		free_grid(command);
		return (127);
	}
	/* Calling Fork */
	valFork = fork();
	if (valFork == -1)
	{
		perror(argv[0]);
		free_grid(command);
		exit(1);
	}
	if (valFork == 0)
	{
		if (execve(full_path, command, env) == -1)
		{	perror(argv[0]);
			free_grid(command);
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
		free_grid(command);
		free(full_path);
	}
	return (statuse);
}


/**
 * free_grid - Function to free allocated space
 * @grid: character pointer
 */

void free_grid(char **grid)
{
	int j = 0;

	if (!grid)
		return;

	while (grid[j])
	{
		free(grid[j]);
		grid[j] = NULL;
		j++;
	}
	free(grid);
	grid = NULL;
}
