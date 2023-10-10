#include "shell.h"

/**
  * custom_print_environment - Display env of built-in variables
  *
  * Return: Nothing
  */
void custom_print_environment(void)
{
	int a = 0, b = 0;

	for (a = 0; environ[a]; a++)
	{
		b = 0;
		do {
			_putchar(environ[a][b]);
			b++;
		} while (environ[a][b]);


		if (b != 0)
			_putchar('\n');
	}
}

