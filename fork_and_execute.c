#include "shell.h"

/**
 * fork_and_execute - Create a new child process and executes the given command
 * @command: Array of strings containing the command and its arguments if any.
 * @prog_name: The name of the current shell program
 * @line_nr: The current line number of the shell program
 *
 * Return: 0 (Success), 1 (Failure)
 */
int fork_and_execute(char *command, char *prog_name, int line_nr)
{
	pid_t child;
	int status = 0, err_status;
	char **argv;

	/* Convert the input command string into an array of string arguments */
	argv = str_to_array(command, " \n");
	free(command);
	if (argv[0] == NULL)
	{
		free_mem(argv);
		return (0);
	}
	/* Check for exit command */
	if (!strcmp(argv[0], "exit"))
	{
		if (argv[1] != NULL)
		{
			err_status = _atoi(argv[1]);
			free_mem(argv);
			exit(err_status);
		}
		free_mem(argv);
		return(1);
	}
	/* Check if the command exists in PATH */
	err_status = check_stat(&argv[0]);
	if (err_status == -1)
	{
		free_mem(argv);
		return (err_status);
	}
	if (err_status == 127)
	{
		print_message(prog_name, line_nr, argv[0], err_status);
		free_mem(argv);
		return (err_status);
	}
	/* Fork a new child process */
	child = fork();
	if (child == -1) /* Forking failed */
	{
		free_mem(argv);
		exit(EXIT_FAILURE);
	}
	else if (child == 0) /* Child Process */
		exec(argv);
	else /* Parent process must wait for child process to terminate */
		wait(&status);
	free_mem(argv);
	return (0);
}
