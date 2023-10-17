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
	pid_t child_process_id;
	int j, statuse;
	char **arr;
	char *tokinz;
	(void)argc, (void)argv;

	while (1)
	{
		if (isatty(0))
		write(STDOUT_FILENO, prompt, strlen(prompt));

		usrinput = getline(&usr_line, &usr_len, stdin);

		if (usrinput == -1)
		{
			if (feof(stdin))
		{
			/* End of file (Ctrl+D) */
			break;
		}
		else
		{
			/* Handle getline error */
			perror("getline");
			exit(EXIT_FAILURE);
		}
		/* Remove the trailing newline character */
		if (usrinput > 0 && usr_line[usrinput - 1] == '\n')
		{
			usr_line[usrinput - 1] = '\0';
		}

		}
		if (strcmp(usr_line, "env\n") == 0)
		{
			env_print(env);
			continue;
		}
		tokinz = strtok(usr_line, " \n");

		arr = malloc(sizeof(char *) * 1024);
		j = 0;

		do {
			arr[j] = tokinz;

			if (j == 0)
			{
				arr[0] = getLocation(arr[0]);
			}
			tokinz = strtok(NULL, " \n");
			j++;
		} while (tokinz);

		arr[j] = NULL;

		/* checking environmental variable */
		if (strcmp(arr[0], "setenv") == 0)
		{
			setEnvVar(arr);
			continue;
		}
		else if (strcmp(arr[0], "unsetenv") == 0)
		{
			unsetEnvVar(arr);
			continue;
		}

		/* Calling the exit_handling function */
		exit_handling(arr);

		j = 0;

		while (arr[j] != NULL)
		{
			ola_printOut("%s\n", arr[j]);
			j++;
		}

		/* Fork a child process */
		child_process_id = fork();

		if (child_process_id == -1)
		{
			/* Handle fork error */
			perror("failed to create a child process");
			exit(EXIT_FAILURE);
		}

		if (child_process_id == 0)
		{
			/* Child process execute using execve */
			if (execve(arr[0], arr, NULL) == -1)
			{
				/* Handle execve error */
				perror("execution failed");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			/* Parent process, wait for the child process to complete */
			wait(&statuse);
		}
		line++;
		free(arr);
	}
	return (0);
}
