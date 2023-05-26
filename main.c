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
	char *s, **argv;

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
		if (s == NULL)
			exit(err_stat);
		argv = str_to_array(s, " \n");
		free(s);
		if (argv == NULL)
			exit(EXIT_FAILURE);
		signal = fork_and_execute(argv);
		if (signal == 1) /* user exitted the program */
		{
			/*exit with previous err value */
			free_mem(argv);
			exit(err_stat);
		}
		if (signal == 127)
			print_message(prog_name, line_nr, argv[0], signal);
		err_stat = signal; /* retain error status value */
		free_mem(argv);
	} while (signal >= 0);

	return (EXIT_SUCCESS);
}
