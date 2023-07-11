#include "main.h"
#include <stdlib.h>

/**
 * argstostr - Concatenate all command line arguments into a single string
 * @ac: Number of arguments
 * @av: Array of command line arguments
 *
 * Return: Pointer to the concatenated string, NULL if failed
 */
char *argstostr(int ac, char **av)
{
	int i, n, r = 0, l = 0;
	char *str;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (n = 0; av[i][n]; n++)
			l++;
	}

	l += ac;

	str = malloc(sizeof(char) * (l + 1));

	if (str == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (n = 0; av[i][n]; n++)
		{
			str[r] = av[i][n];
			r++;
		}

		str[r] = '\n';
		r++;
	}

	str[r] = '\0';

	return (str);
}
