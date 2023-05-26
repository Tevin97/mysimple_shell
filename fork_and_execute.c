#include "shell.h"

/**
 * fork_and_execute - Create a new child process and executes the given command
 * @argv: Array of strings containing the command and its arguments if any.
 *
 * Return: 0 (Success), 1 (Failure)
 */
int fork_and_execute(char **argv)
{
	pid_t child;
	int status = 0, err_status;

	if (argv[0] == NULL)
		return (0);
	/* Check for exit command */
	if (!strcmp(argv[0], "exit"))
	{
		if (argv[1] != NULL)
		{
			err_status = _atoi(argv[1]);
			free_mem(argv);
			exit(err_status);
		}
		return (1);
	}
	/* Check if the command exists in PATH */
	err_status = check_stat(&argv[0]);
	if (err_status == -1)
		return (err_status);
	if (err_status == 127)
		return (err_status);

	/* Fork a new child process */
	child = fork();
	if (child == -1) /* Forking failed */
	{
		return (-1);
	}
	else if (child == 0) /* Child Process */
		exec(argv);
	else /* Parent process must wait for child process to terminate */
		wait(&status);
	return (0);
}
