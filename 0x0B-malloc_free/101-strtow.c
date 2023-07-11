#include <stdlib.h>
#include <string.h>

/**
 * count_words - Helper function to count the number of words in a string
 * @str: String to evaluate
 *
 * Return: Number of words
 */
int count_words(char *str)
{
	int count = 0;
	int word_started = 0;

	while (*str)
	{
		if (*str != ' ')
		{
			if (word_started == 0)
			{
				word_started = 1;
				count++;
			}
		}
		else
		{
			word_started = 0;
		}

		str++;
	}

	return count;
}

/**
 * strtow - Split a string into words
 * @str: String to split
 *
 * Return: Pointer to an array of strings (Success) or NULL (Error)
 */
char **strtow(char *str)
{
	if (str == NULL || *str == '\0')
		return NULL;

	int word_count = count_words(str);

	if (word_count == 0)
		return NULL;

	char **words = malloc(sizeof(char *) * (word_count + 1));

	if (words == NULL)
		return NULL;

	int word_index = 0;
	int word_started = 0;
	char *word_start = NULL;

	while (*str)
	{
		if (*str != ' ')
		{
			if (word_started == 0)
			{
				word_started = 1;
				word_start = str;
			}
		}
		else
		{
			if (word_started == 1)
			{
				word_started = 0;
				int word_length = str - word_start;
				words[word_index] = malloc(sizeof(char) * (word_length + 1));

				if (words[word_index] == NULL)
				{
					for (int i = 0; i < word_index; i++)
						free(words[i]);
					free(words);
					return NULL;
				}

				strncpy(words[word_index], word_start, word_length);
				words[word_index][word_length] = '\0';
				word_index++;
			}
		}

		str++;
	}

	if (word_started == 1)
	{
		int word_length = str - word_start;
		words[word_index] = malloc(sizeof(char) * (word_length + 1));

		if (words[word_index] == NULL)
		{
			for (int i = 0; i <= word_index; i++)
				free(words[i]);
			free(words);
			return NULL;
		}

		strncpy(words[word_index], word_start, word_length);
		words[word_index][word_length] = '\0';
		word_index++;
	}

	words[word_index] = NULL;

	return words;
}
