#include "shell.h"

/**
  * custom_print_environment - Display env of built-in variables
  *
  * Return: Nothing
  */
void custom_print_environment(void)
{
	int a, b;

	for (a = 0; environ[a]; a++)
	{
		for (b = 0; environ[a][b]; b++)
		{
			_putchar(environ[a][b]);
		}

		if (b != 0)
			_putchar('\n');
	}
}
