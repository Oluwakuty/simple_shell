#include "shell.h"

/**
 * exit_me - Function to exit
 * @command: Pointer to pointer to character
 * @statuse: Integer
 */

void exit_me(char **command, int statuse)
{
	spaceFree(command);
	exit(statuse);
}

/**
 * env_me - Function Environemt
 * @command: Pointer to pointer to character
 * @statuse: Integer
 */

void env_me(char **command, int statuse)
{
	int j;
	(void) statuse;

	for (j = 0; environ[j]; j++)
	{
		write(STDOUT_FILENO, environ[j], _strlen(environ[j]));
		write(STDOUT_FILENO, "\n", 1);
	}
	spaceFree(command);
}
