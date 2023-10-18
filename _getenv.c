#include "main.h"
/**
*_getenv - function to get the value of environ
*@name: pointer to the key
*Return: pointer to the value
*/
char *_getenv(char *name)
{
	char **env_var;
	char *string;
	char *token;
	char *value;

	env_var = environ;
	while (env_var)
	{
		string = _strdup(*env_var);
		token = strtok(string, "=");
		if (token != NULL && _strcmp(name, token) == 0)
		{
			token = strtok(NULL, "");
			value = _strdup(token);
			free(string);
			return (value);
		}
		free(string);
		env_var++;
	}
	return (NULL);
}
