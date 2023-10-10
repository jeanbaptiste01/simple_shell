#include "shell.h"

/**
 * _putchar - Writes the character to the standard output
 * @charac: Char to be printed
 *
 * Return: if it is sucessful it will rtn 1,if not it will rtn -1
 */
int _putchar(char charac)
{
	return (write(1, &charac, 1));
}


/**
  * _puts - Prints a string to the standard output followed by a newline
  * @strn: String to be printed
  *
  * Return: empty(nothing)
  */
void _puts(char *strn)
{
	do {
		_putchar(*strn);
		strn++;
	} while (*strn != '\0');

	_putchar('\n');
}

/**
  * custom_string_compare - checks at most 1st char of two string
  * @cstr1: 1st string to compare
  * @cstr2: 2nd string to compare
  * @cn: the maximm number of char to compare
  *
  * Return: The difference between the 1st differ char, or 0 if equal
  */
int custom_string_compare(const char *cstr1, const char *cstr2, size_t cn)
{
	unsigned int custom_pos;
	int custom_diff = 0;

	for (custom_pos = 0; custom_pos < cn; custom_pos++)
	{
		if (cstr1[custom_pos] == cstr2[custom_pos])
		{
			continue;
		}
		else
		{
			custom_diff = cstr1[custom_pos] - cstr2[custom_pos];
			break;
		}
	}

	return (custom_diff);
}


/**
 * custom_reallocate - Adjusts the size of a previously allocated memory block.
 * @ptr: Pointer to the previously allocated memory block
 * @osize: The previous size of the memory block
 * @nsize: The new size to resize the memory block to
 *
 * Return: A new pointer to the memory block with the adjusted size.
 */

void *custom_reallocate(void *ptr, unsigned int osize, unsigned int nsize)
{
	char *new_ptr;
	unsigned int i = 0;

	if (nsize == osize)
		return (ptr);

	if (ptr == NULL)
	{
		new_ptr = malloc(nsize);

		if (new_ptr == NULL)
			return (NULL);

	return (new_ptr);
	}
	else
	{
		if (nsize == 0)
		{
			free(ptr);
			return (NULL);
		}
	}

	new_ptr = malloc(nsize);

	if (new_ptr == NULL)
		return (NULL);

	while (i < osize && i < nsize)
	{
		new_ptr[i] = ((char *)ptr)[i];
		i++;
	}

	free(ptr);
	return (new_ptr);
}
