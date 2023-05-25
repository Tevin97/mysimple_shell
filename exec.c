#include "shell.h"

/**
 * exec - Executes commands from the given file path
 * @argv: Array of strings containing the command and its argumensts if any.
 *
 * Return: 0 on success. Otherwise return 1.
 */
int exec(char **argv)
{
	/* The first element of argv is the command */
	if (argv[0] == NULL)
		return (0);

	/* Exit child process if execution fails */
	if (execve(argv[0], argv, environ) == -1)
	{
		perror("Error");
		exit(1);
	}
	return (0);
}
