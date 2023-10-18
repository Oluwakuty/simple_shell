#include "main.h"
/**
 *getinput - Function to read line
 *Return: pointer to string (Line)
 */
char *getinput(void)
{
	size_t bufsize;
	char *input;

	bufsize = 0;
	input = NULL;
	/* if get line fails */
	if (getline(&input, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(input);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(input);
			perror("error ehile reading");
			exit(EXIT_FAILURE);
		}
	}
	return (input);
}

/**
 *pars_input - split input aand save it in array
 *@input: pointer to string (input)
 * Return: pointer to array pointer
 */

char **pars_input(char *input)
{
	int i, j;
	char *token;
	int counter;
	char **command;

	i = 0;
	if (input == NULL)
	return (NULL);
	counter = count_tokens(input);
	if (counter < 0)
	return (NULL);
	command = malloc(sizeof(char *) * (counter + 1));
	if (command == NULL)
	{
		free(input);
		return (NULL);
	}
	token = strtok(input, " \n\t");
	if (token == NULL)
	{
		free(input);
		free(command);
		return (NULL);
	}
	while (token)
	{
		command[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		if (command[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(command[j]);
			free(command);
			free(input);
			return (NULL);
		}
		_strcpy(command[i], token);
		i++;
		token = strtok(NULL, " \n\t");
	}
	command[counter] = NULL;
	return (command); }

/**
*count_tokens - count number of tokens
*@input: input
*Return: count of tokens
*/

int count_tokens(char *input)
{
	int counter;
	char *input_copy;
	char *token;

	counter = 0;
	input_copy = _strdup(input);
	if (input_copy == NULL)
	return (-1);
	/* Parsing the copy to know words count*/
	token = strtok(input_copy, " \n\t");
	/* Calculate input words (tokens) */
	while (token)
	{
		counter++;
		token = strtok(NULL, " \n\t");
	}
	free(input_copy);
	input_copy = NULL;
	return (counter);
}
