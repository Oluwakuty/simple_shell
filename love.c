#include "shell.h"


/**
 * count_tokinz - Tokens count
 * @usrInput: User line
 * Return: Success
*/

int count_tokinz(char *usrInput)
{
	char *usrCopy;
	int count;
	char *tokinz;

	count = 0;
	usrCopy = _strdup(usrInput);

	if (usrCopy == NULL)
		return (-1);

	for (tokinz = strtok(usrCopy, " \n\t"); tokinz != NULL;
			tokinz = strtok(NULL, " \n\t"))
	{
		count++;
	}
	free(usrCopy);
	usrCopy = NULL;
	return (count);
}


/**
 * _strdup -  Parameter Copier
 * @string: Array
 * Return: Success
 */

char *_strdup(char *string)
{
	char *pointer;
	int zisez;
	int j;

	if (string == NULL)
	{
		return (NULL);
	}
	for (zisez = 0; string[zisez] != '\0'; zisez++)
		continue;
	pointer = (char *)malloc(zisez + 1);
	if (pointer == NULL)
	{
		return (NULL);
	}
	for (j = 0; j < zisez; j++)
	{
		*(pointer + j) = *(string + j);
	}
	*(pointer + zisez) = '\0';
	return (pointer);
}


/**
 *readInput - Function to user line
 *Return: void
 */

char *readInput(void)
{
	char *userInput;
	size_t bufferSize;

	userInput = NULL;
	bufferSize = 0;

	/* Attempt to read a line from stdin */
	if (getline(&userInput, &bufferSize, stdin) == -1)
	{
		/* If getline fails, check if it's due to EOF */
		if (feof(stdin))
		{
			/* If it's EOF, free the userInput and exit with success */
			free(userInput);
			exit(EXIT_SUCCESS);
		}
		else
		{
			/* If getline fails for reasons other than EOF,*/
			free(userInput);
			perror("Error while reading input");
			exit(EXIT_FAILURE);
		}
	}
	/* If getline succeeds, return the userInput */
	return (userInput);
}

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
 * inputSplinter - Function to split user input
 * @spliter: pointer to str
 * Return: Success
 */

char **inputSplinter(char *spliter)
{
	int j, k;
	char *tokinz;
	int count;
	char **cmd;

	j = 0;
	if (spliter == NULL)
		return (NULL);
	count = count_tokinz(spliter);

	if (count < 0)
		return (NULL);
	cmd = malloc(sizeof(char *) * (count + 1));
	if (cmd == NULL)
	{
		free(spliter);
		return (NULL);
	}
	tokinz = strtok(spliter, " \n\t");
	if (tokinz == NULL)
	{
		free(spliter);
		free(cmd);
		return (NULL);
	} while (tokinz)
	{
		cmd[j] = malloc(sizeof(char) * (_strlen(tokinz) + 1));
		if (cmd[j] == NULL)
		{
			for (k = 0; k < j; k++)
				free(cmd[k]);
			free(cmd);
			free(spliter);
			return (NULL);
		}
		_strcpy(cmd[j], tokinz);
		j++;
		tokinz = strtok(NULL, " \n\t");
	}
	cmd[count] = NULL;
	return (cmd); }
