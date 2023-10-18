#include "shell.h"

/**
 * fileOpen - function to open file
 * @argc: Argument Count
 * @argv: Argument vector
 * Return: Always success
 */

FILE *fileOpen(int argc, char *argv[])
{
	FILE *usr_line = stdin;

	if (argc > 1)
	{
		usr_line = fopen(argv[1], "r");
		if (usr_line == NULL)
		{
			perror("fopen");
			exit(EXIT_FAILURE);
		}
	}
	return (usr_line);
}


/**
 * promptDisplay - Function to display prompt
 * @usr_line: character user line
 * Return: Void
 */

void promptDisplay(FILE *usr_line)
{
	if (usr_line == stdin)
	{
		write(STDOUT_FILENO, PROMPT, strlen(PROMPT));
	}
}

/**
 * commandReading - Function to read command
 * @command: Character array
 * @usr_line: file user
 */

void commandReading(char *comand, FILE *usr_line)
{
	char *command = NULL;
	size_t bufsize = MAX_CMD_LEN;

	if (getline(&command, &bufsize, usr_line) == -1)
	{
		if (feof(usr_line))
		{
			if (usr_line != stdin)
			{
				fclose(usr_line);
			}
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("readline");
			exit(EXIT_FAILURE);
		}
		free(command);
		return(0);

	}
}
