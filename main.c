#include "main.h"

/**
 * main - The Main Function
 * @ac: argument count
 * @argv: argument vector
 * Return: Alway Success
*/

int main(int ac, char **argv)
{
	int statuse = 0;
	char *usrInput, **cmd;
	void (*operan)(char **, int);
	(void)ac;

	while (1)
	{
		writePrompt();
		usrInput = readInput();

		if (usrInput == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(usrInput);
			free_grid(cmd);
			return (statuse);
		}
		cmd = inputSplinter(usrInput);
		if (cmd == NULL)
		{
			free_grid(cmd);
			continue;
		}
		free(usrInput);
		operan = bultin_handler(cmd[0]);
		if (operan != NULL)
		{
			operan(cmd, statuse);
		}
		statuse = execution(cmd, argv);
	}
	return (0);
}
