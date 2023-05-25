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

	if (strcmp(env, "") == 0)
	{
		free(env);
		dir = malloc(sizeof(char *) * 2);
		if (dir == NULL)
			return (NULL);
		dir[0] = strdup(".");
		if (dir[0] == NULL)
		{
			free(dir);
			return (NULL);
		}
		dir[1] = NULL;
		return (dir);
	}
	dir = str_to_array(env, ":\n");
	free(env);

	/* If the system fails to allocate memory, exit with failure status*/
	if (dir == NULL)
		exit(EXIT_FAILURE);

	/* Return the 'dir' array of strings */
	return (dir);
}
