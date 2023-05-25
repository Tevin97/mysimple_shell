#include "shell.h"

/**
 * _getenv - Searches for and return the given environment variable
 * @name: The NAME of the variable
 *
 * Return: String containing the VALUE of the environment variable
 */
char *_getenv(const char *name)
{
	int i, j, x, found = 0;
	char *env; /* Will store the VALUE of the environment variable */

	if (name == NULL)
		return (NULL);

	/* Search global array environ for the given variable name */
	for (i = 0; environ[i] != NULL; i++)
	{
		if (!strncmp(environ[i], name, strlen(name)))
		{
			found = 1;
			break;
		}
	}
	if (!found)
		return (NULL);
	j = i;
	/* Set env size to length of the enironment VALUE only */
	env = malloc(strlen(environ[j]) - strlen(name));
	if (env == NULL)
		return (NULL);

	x = strlen(name) + 1;
	/* Uses x to start iterating after the variable NAME and = sign. */
	for (i = x; i < (int) strlen(environ[j]); i++)
	{
		env[i - x] = environ[j][i];
	}
	env[i - x] = '\0';

	return (env);
}
