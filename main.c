#include "shell.h"

/**
 * main - The main shell function
 * @argc: Argument character
 * @argv: Pointer to a pointer to an argument vector
 * @env: Pointer to a pointer to an environment variable
 * Return: Always Success
 */

int main(int argc, char **argv, char **env)
{
	char *usr_line = NULL;
	size_t usr_len = 0;
	ssize_t usrinput;
	int line = 1;
	char *prompt = "Oluwakuti $ ";
	char **arr;
	int j;
	(void)argc, (void)argv;

	while (1)
	{
		if (isatty(0))
			write(STDOUT_FILENO, prompt, strlen(prompt));
		usrinput = getline(&usr_line, &usr_len, stdin);
		handleUserInput(usr_line, usrinput, env);
		arr = tokenizeUserInput(usr_line);

		if (handleEnvVars(arr))
			continue;

		/* Calling the exit_handling function */
		exit_handling(arr);
		j = 0;

		while (arr[j] != NULL)
		{
			ola_printOut("%s\n", arr[j]);
			j++;
		}
		executeCommand(arr);
		line++;
		free(arr);
	}
	return (0);
}
