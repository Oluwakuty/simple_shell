#include "shell.h"

/**
 * main - Main Simple Shell File
 * @argc: Argument count
 * @argv: Character argument vector
 * Return: Success always
 */

int main(int argc, char *argv)
{
	char command[MAX_CMD_LEN];
	char *args[11];
	FILE *usr_line;

	usr_line = fileOpen(argc, argv);

	while (true)
	{
		promptDisplay(usr_line);
		memset(command, 0, MAX_CMD_LEN);
		commandReading(command, usr_line);
		tokeniser(command, args);
		exitHandling(args, usr_line);

		if (strcmp(args[0], "env") == 0)
		{
			envHandle();
			continue;
		}
		char *envPath = getenv("PATH");
		char *binDirectory = strtok(envPath, ":");

		do {
			commandExecution(args, binDirectory, &statuse, &process_id);
			binDirectory = strtok(NULL, ":");
		} while (binDirectory != NULL);

		if (binDirectory == NULL)
		{
			write(STDOUT_FILENO, "Command not found\n", 18);
		}
	}
	return (EXIT_SUCCESS);
}
