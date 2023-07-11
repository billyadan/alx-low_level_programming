Copy code
#include "main.h"
#include <stdlib.h>

/**
 * str_concat - Concatenate two strings
 * @s1: First string
 * @s2: Second string
 *
 * Return: Pointer to the concatenated string, NULL if failed
 */
char *str_concat(char *s1, char *s2)
{
	char *concat;
	int i, j, len1 = 0, len2 = 0;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	for (i = 0; s1[i] != '\0'; i++)
		len1++;

	for (j = 0; s2[j] != '\0'; j++)
		len2++;

	concat = malloc(sizeof(char) * (len1 + len2 + 1));

	if (concat == NULL)
		return (NULL);

	for (i = 0; s1[i] != '\0'; i++)
		concat[i] = s1[i];

	for (j = 0; s2[j] != '\0'; j++, i++)
		concat[i] = s2[j];

	concat[i] = '\0';

	return (concat);
}
