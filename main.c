#include "main.h"
/**
*main - main function
*@ac: arg count
*@argv: argument vector
*@env: environ variable
*Return: 0 on success
*/

int main(int ac, char **argv)
{
	int status;
	char *input;
	char **command;
	void (*operation)(char **, int status);
	(void)ac;
	 

	input = NULL;
	status = 0;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		/* Read input */
		input = getinput();

		if (input == NULL) /* EOF */
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(input);
			input = NULL;
			free_grid(command);
			return (status);
		}

		/* Parse the input*/
		command = pars_input(input);

		if (command == NULL)
		{
			free_grid(command); /********/
			continue;
		}
		free(input);
		/* If the command is built-in command */
		operation = handle_builtin(command[0]);
		if (operation != NULL)
			{
				operation(command, status);

			}

	status = execute(command, argv);
	}
	return (0);
}

