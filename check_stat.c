#include "shell.h"

char *concat_path(const char *s1, const char *s2);

/**
 * check_stat - Checks whether the given file existsi and returns the filepath.
 * @filename: The filename
 *
 * Description: Checks whether the given file (filepath) exists. Also checks
 * PATH environment variable for matching executables, and returns the
 * executable's filepath.
 * Return: 0 on success. Otherwise return error status..
 */
int check_stat(char **filename)
{
	unsigned int i;
	struct stat st;
	char **paths;
	char *str;

	if (stat(*filename, &st) == 0)
		return (0);

	paths = path();
	if (paths == NULL)
		return (-1);

	for (i = 0; paths[i] != NULL; i++)
	{
		str = concat_path(paths[i], *filename);
		if (str == NULL)
		{
			free_mem(paths);
			exit(EXIT_FAILURE);
		}

		if (stat(str, &st) == 0)
		{
			free(*filename);
			*filename = str;
			free_mem(paths);
			return (0);
		}

	}
	free_mem(paths);
	return (1);
}

/**
 * concat_path - Concatenates two strings (a filename to a directory path)
 * @s1: The first string to be concatenated (dirctory filepath).
 * @s2: The second string to be concatenated (filename).
 *
 * Return: New concatenated string. On failure return NULL.
 */
char *concat_path(const char *s1, const char *s2)
{
	size_t size, i, j;
	char *str;

	if (s1 == NULL || s2 == NULL)
	{
		return (NULL);
	}

	size = strlen(s1) + 1 + strlen(s2);
	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
	{
		return (NULL);
	}

	for (i = 0; s1[i] != '\0'; i++)
	{
		str[i] = s1[i];
	}
	str[i] = '/';
	i++;
	for (j = 0; s2[j] != '\0'; j++, i++)
	{
		str[i] = s2[j];
	}
	str[i] = '\0';

	return (str);
}
