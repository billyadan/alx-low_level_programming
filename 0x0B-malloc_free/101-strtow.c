#include <stdlib.h>
#include "main.h"

/**
 * count_word - Count the number of words in a string
 * @s: String to evaluate
 *
 * Return: Number of words
 *
 * Description: This function counts the number of words in a string.
 * A word is defined as a sequence of non-space characters separated by spaces.
 */
int count_word(char *s)
{
	int flag = 0;
	int c, w = 0;

	for (c = 0; s[c] != '\0'; c++)
	{
		if (s[c] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			w++;
		}
	}

	return (w);
}

/**
 * strtow - Split a string into words
 * @str: String to split
 *
 * Return: Pointer to an array of strings (Success) or NULL (Error)
 *
 * Description: This function splits a string into individual words.
 * It allocates memory for the words and stores them in an array of strings.
 * The words are separated by spaces, and the last element of the array is NULL.
 * If the input string is NULL or empty, or if memory allocation fails, NULL is returned.
 */
char **strtow(char *str)
{
	char **matrix;
	char *tmp;
	int i, k = 0, len = 0, words, c = 0, start, end;

	if (str == NULL || *str == '\0')
		return NULL;

	len = 0;
	while (str[len] != '\0')
		len++;

	words = count_word(str);

	if (words == 0)
		return NULL;

	matrix = malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
		return NULL;

	for (i = 0; i <= len; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			if (c)
			{
				end = i;
				tmp = malloc(sizeof(char) * (c + 1));
				if (tmp == NULL)
				{
					for (i = 0; i < k; i++)
						free(matrix[i]);
					free(matrix);
					return NULL;
				}

				for (int j = start; j < end; j++)
					tmp[j - start] = str[j];
				tmp[c] = '\0';
				matrix[k] = tmp;
				k++;
				c = 0;
			}
		}
		else if (c++ == 0)
			start = i;
	}

	matrix[k] = NULL;

	return matrix;
}
