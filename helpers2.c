#include "main.h"
/**
 *execute - exectute the program
 *@command: command
 *@argv: argv
 *@env: environ var
 *Return: 0 on success
 */

int execute(char **command, char **argv)
{
	pid_t fork_value;
	int status;
	char **env = environ;
	char *full_path;

	full_path = get_cmd(command[0]);
	if (!full_path)
	{
		printf("not found\n"); /*PRINT error ****/
		free_grid(command);
		return (127);
	}
		fork_value = fork();
		if (fork_value == -1) /* if fork fails */
		{
			perror(argv[0]);
			free_grid(command);
			exit(1);
		}
		if (fork_value == 0) /* on child process */
		{
			if (execve(full_path, command, env) == -1)
			{
				perror(argv[0]);
				free_grid(command);
				free(full_path); full_path = NULL;
				/* exit(127);*/ /**********/ 
			}
		}
			/* else
			{
				perror(argv[0]);
				free_grid(command);
				free(full_path); full_path = NULL;
				exit(127);
			}
			free(full_path);
			} */
		/* on parent process */
		else
		{
			waitpid(fork_value, &status, 0);
			if (status == -1)
				perror("wait error");
			free_grid(command);
			free(full_path);
		}
	return (status);
}


/**
 * free_grid - free 2d array
 * @grid: pointer
 */
void free_grid(char **grid)
{
	int i;

	if (!grid)
		return;
	for (i = 0; grid[i]; i++)
	{
		free(grid[i]);
		grid[i] = NULL;
	}

	free(grid);
	grid = NULL;
}
