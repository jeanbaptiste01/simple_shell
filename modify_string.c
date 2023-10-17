#include "shell.h"

/**
 * modify_string - Removes any new line character from a given string.
 * @input_string: The input string to be modified.
 *
 * Return: The modified string without any new line characters.
 */

char *modify_string(char *input_string)
{
	int a;

	for (a = 0; input_string[a]; a++)
	{
		if (input_string[a] == '\n')
			input_string[a] = '\0';
	}

	return (input_string);
}
