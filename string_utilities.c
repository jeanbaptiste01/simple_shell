#include "shell.h"

/**
  * custom_concat - Combines two strings
  * @target: The string to which the other string will be appended
  * @extension: The string to append
  *
  * Return: A pointer to the modified target string
  */
char *custom_concat(char *target, char *extension)
{
	int target_length = 0, i = 0;

	/* Determine the length of the target string */
	for (; target[target_length]; target_length++)
		;

	/* Append the extension string to the target */
	do {
		target[target_length] = extension[i];
		target_length++;
		i++;
	} while (extension[i] != '\0');

	/* Add null terminator to indicate end of string */
	target[target_length] = '\0';

	return (target);
}

/**
  * custom_length - Calculates the length of a string
  * @strinput: The string to be measured
  *
  * Return: The length of the string
  */
int custom_length(const char *strinput)
{
	int i = 0;

/* Iterate through the string until a null character is encountered */
	do {
		i++;
	} while (strinput[i]);

	return (i); /* Return the length of the string */
}

/**
  * custom_compare - Compares two strings in lexicographical order.
  * @strA: The initial string for comparison.
  * @strB: The string to compare against.
  *
  * Return: The ASCII value difference of the first differing characters,
  * or 0 if the strings are identical.
  */
int custom_compare(char *strA, char *strB)
{
	int lengthA;
	int lengthB;
	int limit;

	/* Initialize position for iteration */
	/* Initialize the difference value */
	int position = 0, difference = 0;

	/* Calculate the lengths of the input strings */
	lengthA = custom_length(strA);
	lengthB = custom_length(strB);
	/* Determine the limit for comparison based on the shorter string */
	limit = (lengthA <= lengthB) ? lengthA : lengthB;

	/* Iterate through the strings to find the first differing character */
	for (position = 0; position <= limit; position++)
	{
		/* Compare characters at the current position */
		if (strA[position] == strB[position])
		{
			/* Characters match, continue to the next position */
			continue;
		}
		else
		{
			/* Characters differ, calculate the ASCII difference */
			difference = strA[position] - strB[position];
			break; /* Exit the loop */
		}
	}

	return (difference); /* Return the ASCII difference */
}

/**
  * custom_duplicate - Duplicates the original string.
  * @original: The original string to be duplicated.
  *
  * Return: A pointer to the newly duplicated string.
  */
char *custom_duplicate(char *original)
{
	int index = 0, length = 1;
	char *duplicate_string;

	/* Check if the original string is NULL */
	if (original == NULL)
		return (NULL);

	/* Calculate the length of the original string */
	length = custom_length(original);

	/* Allocate memory for the duplicated string */
	duplicate_string = malloc((sizeof(char) * length) + 1);

	/* Check if memory allocation was successful */
	if (duplicate_string == NULL)
		return (NULL);

	/* Copy characters from the original to the duplicate string */
	do {
		duplicate_string[index] = original[index];
		index++;
	} while (index < length);

	/* Add a null terminator to the end of the duplicate string */
	duplicate_string[index] = '\0';

	/* Return the duplicated string */
	return (duplicate_string);
}

/**
  * custom_convert_to_integer - Converts a string to an integer.
  * @str: The pointer to the input string.
  *
  * Return: The converted integer.
  */
int custom_convert_to_integer(char *str)
{
	int sign = 1, is_integer = 0, position = 0;
	unsigned int result = 0;

	/* Iterate through each character in the input string */
	while (str[position])
	{
		/* Handle negative sign if present */
		if (str[position] == '-')
			sign *= -1;

		/* Process digits and convert them to an integer */
		for (; str[position] >= '0' && str[position] <= '9'; position++)
		{
			is_integer = 1;
			result = (result * 10) + (str[position] - '0');
		}

		/* If at least one digit is processed, exit the loop */
		if (is_integer == 1)
			break;

		/* Move to the next character in case no digit is processed */
		position++;
	}

	/* Apply sign to the result and return the final integer */
	result *= sign;
	return (result);
}
