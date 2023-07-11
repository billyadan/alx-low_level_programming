#include "main.h"
#include <stdlib.h>

/**
 * create_array - Create an array of size 'size' and assign character 'c'
 * @size: Size of the array
 * @c: Character to assign
 *
 * Return: Pointer to the created array, NULL if failed
 */
char *create_array(unsigned int size, char c)
{
	char *str;
	unsigned int i;

	if (size == 0)
		return (NULL);

	str = malloc(sizeof(char) * size);
	if (str == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		str[i] = c;

	return (str);
}
