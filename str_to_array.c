#include "shell.h"

/**
 * str_to_array - Splits a string into an array of strings (separate words)
 * @str: The string to be split up
 * @delim: Set of bytes that delimit the string
 *
 * Return: The array of strings.
 * Description: The function converts the given string into an array seperate
 * strings as determined by the delimiter. Last element of the array is NULL.
 */
char **str_to_array(char *str, char *delim)
{
	char **str_array; /* Declare a pointer to a character array called str_array*/
	char *token, *s; /* Declare two character pointers token and s*/
	int i = 0; /*Initialize integer i with 0*/

	str_array = malloc(sizeof(char *)); /* Allocate memory for str_array*/

	if (str_array == NULL) /*If allocation fails*/
	{
		perror("memory allocation failed"); /*print error message*/
		exit(EXIT_FAILURE); /* Exit the program with status failure*/
	}

	s = str; /* Store the input string into s*/
	/* Tokenise the given string and store tokens into array */
	while ((token = strtok(s, delim)) != NULL)
	{
		str_array[i] = strdup(token);

		if (str_array[i] == NULL)
		{
		/* Free all memory and exit if malloc fails. */
			perror("memory allocation failed");
			for (i -= 1; i >= 0; i--)
				free(str_array[i]);
			free(str_array);
			exit(EXIT_FAILURE);
		}

		i++;
		/* Increment the size of the string array */
		str_array = realloc(str_array, sizeof(char *) * (i + 1));
		s = NULL;
	}
	str_array[i] = NULL;
	return (str_array);
}
