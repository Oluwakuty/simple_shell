#include "main.h"

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
