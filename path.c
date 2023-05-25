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
	dir = str_to_array(env, ":\n");

	free(env);

	/* If the system fails to allocate memory, exit with failure status*/
	if (dir == NULL)
		exit(EXIT_FAILURE);

	/* Return the 'dir' array of strings */
	return (dir);
}
