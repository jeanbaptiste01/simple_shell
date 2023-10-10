#include "shell.h"

/**
 * custom_count_words - Counts the number of words in the provided string.
 * @user_input: The string to analyze.
 *
 * Return: The count of words in the string.
 */

int custom_count_words(char *user_input)
{
	int countWords;
	int wordDetected = 0, isSpace = 0;

	for (countWords = 0; user_input[countWords] != '\0'; countWords++)
	{
		if (user_input[countWords] == ' ' || user_input[countWords]
			== '\n' || user_input[countWords] == '\t')
			isSpace = 0;
		else if (isSpace == 0)
		{
			isSpace = 1;
			wordDetected++;
		}
	}

	return (wordDetected);
}

/**
 * custom_count_occurrences - Counts the occurrences of characters in a string.
 * @wstr: The string to search for occurrences.
 * @occurrences: The characters to count occurrences of.
 *
 * Return: The number of occurrences of characters in the string.
 */

int custom_count_occurrences(char *wstr, char *occurrences)
{
	int idx_wstr = 0, idx_delim = 0, count_occurrences = 0;

	do {
		idx_wstr = 0;
		do {
			if (wstr[idx_wstr] == occurrences[idx_delim])
				count_occurrences++;
			idx_wstr++;
		} while (wstr[idx_wstr]);

		idx_delim++;
	} while (occurrences[idx_delim]);

	return (count_occurrences);
}
