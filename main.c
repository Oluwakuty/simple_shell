#include "shell.h"

/**
 * main - The Main Function
 * @ac: argument count
 * @argv: argument vector
 * Return: Alway Success
*/

int main(int ac, char **argv)
{
	int statuse = 0;
	char *usrInput, **command;
	void (*operan)(char **, int statuse);
	(void)ac;

	usrInput = NULL;

	while (1)
	{
		writePrompt();
		usrInput = readInput();

		if (usrInput == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(usrInput);
			spaceFree(command);
			return (statuse);
		}
		command = inputSplinter(usrInput);
		if (command == NULL)
		{
			spaceFree(command);
			continue;
		}
		free(usrInput);
		operan = bultin_handler(command[0]);
		if (operan != NULL)
		{
			operan(command, statuse);
		}
		statuse = execution(command, argv);
	}
	return (0);
}
