#include "shell.h"

/**
 * tokenizer - Function to tokenize user input
 * @command: character pointer
 * @args: Arguments
 */

void tokenizer(char *command, char *args[])
{
	int t;

	for (t = 0; t < 11; t++)
	{
		args[t] = strtok(t == 0 ? command : NULL, " ");
		if (args[t] == NULL)
			break;
	}
}


/**
 * exitHandling - Functions to handle exit
 * @args: character argument
 * @usr_line: File user line
 */

void exitHandling(char *args[], FILE *usr_line)
{
	if (strcmp(args[0], "exit") == 0)
	{
		if (usr_line != stdin)
		{
			fclose(usr_line);
		}
		exit(EXIT_SUCCESS);
	}
}
