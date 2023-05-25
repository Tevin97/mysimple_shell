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
	int signal = 0, err_stat = 0;
	char *s;

	prog_name = av[0];
	/* If program is run with arguments, exit with error message */
	if (ac > 1)
	{
		err_stat = 2;
		print_message(prog_name, line_nr, av[1], err_stat);
		exit(127);
	}

	/* Prompt user and execute indefinitely until program is exited */
	do {
		line_nr++;
		s = prompt();
		signal = fork_and_execute(s, prog_name, line_nr);
		if (signal == 1) /* user exited program */
		       exit(err_stat);	
		err_stat = signal; /* retain error status value */
	} while (signal >= 0);

	return (EXIT_SUCCESS);
}
