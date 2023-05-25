#include "shell.h"

/**
 * prompt - Prompts the user for an input.
 *
 * Return: The user input string.
 */
char *prompt(void)
{
	int n_chars = 0; /* no of character read */
	char *buff = NULL; /* buffer to store user input */
	size_t n = 0; /* size of buffer - automatically updated by getline*/
	char *ps; /* Prompt string */

	/* This line of code assigns a string literal to the variable ps*/
	ps = "($) ";

	/**
	 * Display prompt only if shell is in interactive mode
	 * i.e. if the input is from the terminal
	 */
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, ps, strlen(ps));

	/**
	 * Read the user input:
	 * getline function automatically allocates sufficient memory to buff.
	 */
	n_chars = getline(&buff, &n, stdin);
	/* Handle EOF from input stream (CTL+D) */
	if (n_chars < 1)
	{
		if (isatty(STDIN_FILENO))
			/* Print new line when in interactive mode */
			write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_SUCCESS);
	}
	return (buff);
}
