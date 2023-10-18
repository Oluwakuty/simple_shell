#include "main.h"

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
	return(0);
}


/**
 * _strcpy - String Copier
 * @destination : Array pointer
 * @source : Array pointer
 * Return: Success
 */

char *_strcpy(char *destination, char *source)
{
	int j;

	for (j = 0; source[j]; j++)
	{
		destination[j] = source[j];
	}
	destination[j] = '\0';
	return (destination);
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
