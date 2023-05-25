/**
 * _atoi - Converts a string to an integer
 * @s: String to be converted to an integer
 *
 * Return: The integer converted from the string
 */
int _atoi(char *str)
{
	int n = 0, i, sign = 1, found = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (!found)
		{
			if (str[i] == '-')
				sign *= -1;
			if (str[i] >= '1' && str[i] <= '9')
				found = 1;
		}
		if (found)
		{
			if (!(str[i] >= '0' && str[i] <= '9'))
				break;
			n = n * 10 + sign * (str[i] - '0');
		}
	}
	return (n);
}
