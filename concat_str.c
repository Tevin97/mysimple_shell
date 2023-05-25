#include "shell.h"

/**
 * concat_str - Concatenates two strings
 * @s1: The first string to be concatenated.
 * @s2: The second string to be concatenated.
 *
 * Return: New concatenated string. On failure return NULL.
 */
char *concat_str(const char *s1, const char *s2)
{
	size_t size, i, j;
	char *str, *result;

	if (s1 == NULL || s2 == NULL)
	{
		return (NULL);
	}

	size = strlen(s1) + strlen(s2);
	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
	{
		return (NULL);
	}

	for (i = 0; s1[i] != '\0'; i++)
	{
		str[i] = s1[i];
	}
	for (j = 0; s2[j] != '\0'; j++, i++)
	{
		str[i] = s2[j];
	}
	str[i] = '\0';

	result = strdup(str);
	free(str);

	return (result);
}
