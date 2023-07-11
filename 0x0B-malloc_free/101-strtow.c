#include <stdlib.h>
#include <string.h>

/**
 * count_words - helper function to count the number of words in a string
 * @s: string to evaluate
 *
 * Return: number of words
 */
int count_words(const char *s)
{
    int count = 0;
    int is_word = 0;
    size_t len = strlen(s);

    for (size_t i = 0; i < len; i++)
    {
        if (s[i] != ' ' && !is_word)
        {
            is_word = 1;
            count++;
        }
        else if (s[i] == ' ')
        {
            is_word = 0;
        }
    }

    return count;
}

/**
 * strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (Success) or NULL (Error)
 */
char **strtow(const char *str)
{
    if (str == NULL || *str == '\0')
        return NULL;

    int word_count = count_words(str);
    if (word_count == 0)
        return NULL;

    char **matrix = malloc(sizeof(char *) * (word_count + 1));
    if (matrix == NULL)
        return NULL;

    const char *word_start = NULL;
    int word_index = 0;
    int in_word = 0;

    for (size_t i = 0; i <= strlen(str); i++)
    {
        if (str[i] != ' ' && !in_word)
        {
            in_word = 1;
            word_start = &str[i];
        }
        else if ((str[i] == ' ' || str[i] == '\0') && in_word)
        {
            in_word = 0;
            size_t word_length = &str[i] - word_start;

            char *word = malloc(sizeof(char) * (word_length + 1));
            if (word == NULL)
            {
                // Free previously allocated memory
                for (int j = 0; j < word_index; j++)
                    free(matrix[j]);
                free(matrix);
                return NULL;
            }

            strncpy(word, word_start, word_length);
            word[word_length] = '\0';
            matrix[word_index] = word;
            word_index++;
        }
    }

    matrix[word_index] = NULL;

    return matrix;
}
