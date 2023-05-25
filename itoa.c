#include "shell.h"

/**
 * _itoa - Converts an integer to a string
 * @n: The integer to be converted
 *
 * Return: The string representing
 */
char *_itoa(unsigned int n)
{
	char str[20];
	char *s;
	unsigned int i, j;

	/* initialise the array */
	for (i = 0; i < 20; i++)
	{
		str[i] = '\0';
	}

	/* store each digit into the array */
	for (i = 0; ; i++)
	{
		str[i] = (n % 10) + '0';
		if (n > 10)
			n = n / 10;
		else
			break;
	}

	j = i;
	s = malloc(sizeof(char) * strlen(str) + 1);

	/* store the digits from the array into string in the correct order */
	for (i = 0; i <= j; i++)
	{
		s[i] = str[j - i];
	}
	s[i] = '\0';

	/* free the memory before returning*/
	free(s);

	return (s);
}
