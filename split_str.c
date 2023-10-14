#include "shell.h"

/**
 * split_string - Splits a string into an array of tokens
 * @input_str: The input string to be tokenized
 * @del_char: The delimiter character for tokenization
 * @max_tokens: The maximum number of tokens expected
 *
 * Return: An array containing the tokens extracted from the string
 */

char **split_string(char *input_str, char *del_char, int max_tokens)
{
	char **token_array = NULL;
	char *current_token = NULL;
	char *temporary_token = NULL;
	int i;

	token_array = malloc(sizeof(char *) * (max_tokens + 1));
	if (!token_array)
		return (NULL);

	input_str = modify_string(input_str);
	temporary_token = custom_duplicate(input_str);
	current_token = strtok(temporary_token, del_char);

	for (i = 0; current_token; i++)
	{
		token_array[i] = custom_duplicate(current_token);
		current_token = strtok(NULL, del_char);
	}

	token_array[i] = NULL;
	free(temporary_token);
	return (token_array);
}
