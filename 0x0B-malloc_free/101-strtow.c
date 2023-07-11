#include <stdlib.h>
#include "main.h"

/**
 * count_word - Helper function to count the number of words in a string
 * @s: String to evaluate
 *
 * Return: Number of words
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
 * copy_word - Helper function to copy a word from the string
 * @src: Source string to copy from
 * @start: Starting index of the word
 * @end: Ending index of the word
 *
 * Return: Pointer to the copied word
 */
char *copy_word(char *src, int start, int end)
{
	char *word;
	int i;

	word = malloc(sizeof(char) * (end - start + 1));
	if (word == NULL)
		return (NULL);

	for (i = 0; start < end; i++, start++)
		word[i] = src[start];

	word[i] = '\0';

	return (word);
}

/**
 * fill_matrix - Helper function to fill the matrix with words
 * @matrix: Pointer to the matrix
 * @str: String to split
 * @words: Number of words
 */
void fill_matrix(char **matrix, char *str, int words)
{
	int i, k = 0, len = 0, c = 0, start, end;

	while (*(str + len))
		len++;

	for (i = 0; i <= len; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			if (c)
			{
				end = i;
				matrix[k] = copy_word(str, start, end);

				if (matrix[k] == NULL)
				{
					for (i = 0; i < k; i++)
						free(matrix[i]);
					free(matrix);
					return;
				}

				k++;
				c = 0;
			}
		}
		else if (c++ == 0)
			start = i;
	}

	matrix[k] = NULL;
}

/**
 * strtow - Split a string into words
 * @str: String to split
 *
 * Return: Pointer to an array of strings (Success) or NULL (Error)
 */
char **strtow(char *str)
{
	char **matrix;
	int words;

	if (str == NULL || *str == '\0')
		return (NULL);

	words = count_word(str);

	if (words == 0)
		return (NULL);

	matrix = malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
		return (NULL);

	fill_matrix(matrix, str, words);

	return (matrix);
}
