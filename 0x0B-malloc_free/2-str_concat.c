#include "main.h"
#include <stdlib.h>

/**
 * str_concat - Concatenate two strings
 * @s1: First string to concatenate
 * @s2: Second string to concatenate
 *
 * Return: Pointer to the concatenated string, NULL if failed
 */
char *str_concat(char *s1, char *s2)
{
	char *concat;
	int len1 = 0, len2 = 0, i, j;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	for (len1 = 0; s1[len1] != '\0'; len1++)
		;

	for (len2 = 0; s2[len2] != '\0'; len2++)
		;

	concat = malloc(sizeof(char) * (len1 + len2 + 1));

	if (concat == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		concat[i] = s1[i];

	for (j = 0; j < len2; j++)
		concat[i++] = s2[j];

	concat[i] = '\0';

	return (concat);
}
