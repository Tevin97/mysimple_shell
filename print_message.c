#include "shell.h"

char *gen_prefix(const char *prog_name, const int line_nr);
char *gen_message(const char *prefix, const char *op2, const char *op3);

/**
 * print_message - Prints an error message to stderr
 * @prog_name: The name of the current shell program
 * @line_nr: The current line number of the shell program
 * @command: Command that was entered by the user that failed
 * @err_status: Status indicating the reason the command failed
 *
 * Return: Nothing
 */
void print_message(char *prog_name, int line_nr, char *command, int err_status)
{
	/* Declare pointers for prefix and message strings*/
	char *prefix;
	char *message;

	/* If there is no error (i.e. err_status is zero), return and do nothing */
	if (err_status == 0)
		return;

	/* Generate the prefix message using gen_prefix()*/
	prefix = gen_prefix(prog_name, line_nr);
	if (prefix == NULL)
		exit(EXIT_FAILURE);

	/* Generate the error message using gen_message() for err_status 1*/
	if (err_status == 127)
	{
		message = gen_message(prefix, command, ": not found\n");
		if (message == NULL)
		{
			free(prefix);
			exit(EXIT_FAILURE);
		}
		/* Write the error message to stderr*/
		write(2, message, strlen(message));
	}
	if (err_status == 2)
	{
		message = gen_message(prefix, "Can't open ", command);
		if (message == NULL)
		{
			free(prefix);
			exit(EXIT_FAILURE);
		}
		write(2, message, strlen(message));
		write(2, "\n", 1);
	}

	/* Free the memory allocated by prefix and message*/
	free(prefix);
	free(message);
}

/**
 * gen_message - Generates a string for the output error message
 * @prefix: First part of the string (containing program name and line number)
 * @op2: Second part of the message (depends on the error)
 * @op3: Third part of the message (depends on the error)
 *
 * Return: Complete message. Otherwise return NULL on failure.
 */
char *gen_message(const char *prefix, const char *op2, const char *op3)
{
	char *str, *ss;

	ss = concat_str(prefix, op2);
	if (ss == NULL)
		return (NULL);

	str = concat_str(ss, op3);
	free(ss);
	if (str == NULL)
		return (NULL);

	return (str);
}

/**
 * gen_prefix - generates a string with the prefix of the error message. This
 * part contains the program name and the line number of the current shell.
 * @prog_name: The name of shell program
 * @line_nr: The line number of the shell
 *
 * Return: Message prefix
 */
char *gen_prefix(const char *prog_name, const int line_nr)
{
	char *str, *s1, *s2, *s_lnr;

	s_lnr = _itoa(line_nr);
	if (s_lnr == NULL)
		return (NULL);

	s1 = concat_str(prog_name, ": ");
	if (s1 == NULL)
	{
		free(s_lnr);
		return (NULL);
	}

	s2 = concat_str(s_lnr, ": ");
	free(s_lnr);
	if (s2 == NULL)
	{
		free(s1);
		return (NULL);
	}

	str = concat_str(s1, s2);
	free(s1);
	free(s2);
	if (str == NULL)
		return (NULL);

	return (str);
}
