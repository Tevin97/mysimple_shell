#include "shell.h"

/**
 * path - Returns a array of strings containing all the directories that are in
 * the PATH environment variable.
 *
 * Return: Nothing.
 */
char **path(void)
{
	char *env; /* Environment variable */
	char **dir; /* String array of directories */

	env = _getenv("PATH");
	if (env == NULL)
		return (NULL);

	if (strcmp(env, "") == 0)
	{
		free(env);
		env = strdup(".");
		if (env == NULL)
			return (NULL);
	}

	dir = str_to_array(env, ":\n");
	free(env);
	/* If the system fails to allocate memory, exit with failure status*/
	if (dir == NULL)
		return (NULL);

	/* Return the 'dir' array of strings */
	return (dir);
}
