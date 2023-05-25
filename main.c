#include "shell.h"

/**
 * main - Test suite for simple shell program / Entry point
 * @ac: Number of command line arguments
 * @av: Array of command line arguments
 *
 * Return: 0 (SUCCESS)
 */
int main(int ac, char **av)
{
	char *prog_name; /* Shell program name */
	int line_nr = 0; /* The current line number of the shell program*/
	int status = 0;
	char *s;

	prog_name = av[0];
	/* If program is run with arguments, exit with error message */
	if (ac > 1)
	{
		status = 2;
		print_message(prog_name, line_nr, av[1], status);
		exit(127);
	}

	/* Prompt user and execute indefinitely until program is exited */
	do {
		line_nr++;
		s = prompt();
		if (strcmp(s, "exit") == 0)
			break;
		status = fork_and_execute(s, prog_name, line_nr);
	} while (status >= 0);

	return (EXIT_SUCCESS);
}
