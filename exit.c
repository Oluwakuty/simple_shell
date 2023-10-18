#include "main.h"

/**
 * bultin_handler - function to handle exit
 * @str: character string
 * Return: void
 */

void (*bultin_handler(char *str))(char **, int statuse)
{
	sp_t fun_list[] = {
		{"exit", exit_me},
		{"env", env_me},
		{NULL, NULL}
	};
	int j;

	for (j = 0; fun_list[j].command; j++)
	{
		if (_strcmp(fun_list[j].command, str) == 0)
			return (fun_list[j].func);
	}
	return (NULL);
}


/**
 * exit_me - Function to exit
 * @command: Pointer to pointer to character
 * @statuse: Integer
 */

void exit_me(char **command, int statuse)
{
	free_grid(command);
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
	free_grid(command);
}
