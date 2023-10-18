#include "shell.h"


/**
 * _strlen - Returns the length of a string
 * @s : str
 * Return: Success
 */

int _strlen(char *s)
{
	int j;

	for (j = 0; s[j] != '\0'; j++)
	{
		return (j);
	}
	return (0);
}


/**
 * _strcmp - Strings comparison
 * @str1: First pointer string
 * @str2: second pointer string
 * Return: Success
 */

int _strcmp(char *str1, char *str2)
{
	size_t j = 0;

	while (str1[j] != '\0' || str2[j] != '\0')
	{
		if (str1[j] != str2[j])
		{
			return (str1[j] - str2[j]);
		}
		j++;
	}
	return (0);
}


/**
 * _strcat - String Concantenation
 * @source: Copied string
 * @destination: String
 * Return: Success
 */

char *_strcat(char *destination, char *source)
{
	int j = 0;
	int lentDest =  _strlen(destination);
	int lenSrc =  _strlen(source);

	while (j < lenSrc)
	{
		destination[lentDest + j] = source[j];
		j++;
	}
	destination[lentDest + j] = '\0';
	return (destination);
}


/**
 * envGetting - environment function to get value
 * @naming: pointer to the key
 * *Return: Success
 */

char *envGetting(char *naming)
{
	char **envVariable;
	char *str;
	char *tokinz;
	char *val;

	for (envVariable = environ; *envVariable != NULL; envVariable++)
	{
		str = _strdup(*envVariable);
		tokinz = strtok(str, "=");

		if (tokinz != NULL && _strcmp(naming, tokinz) == 0)
		{
			tokinz = strtok(NULL, "");
			val = _strdup(tokinz);
			free(str);
			return (val);
		}
		free(str);
	}
	return (NULL);
}
