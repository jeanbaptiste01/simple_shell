#include "shell.h"

/**
 * get_environment_variable - Retrieves the value of a specific
 * environment variable.
 * @enviname: The name of the environment variable to search for.
 *
 * Return: The value of the specified environment variable,or NULL if not found
 */

char *get_environment_variable(const char *enviname)
{
	int k;
	char *ev = NULL;

	for (k = 0; environ[k]; k++)
	{
		if (custom_string_compare(enviname,
		environ[k], custom_length(enviname)) == 0)
		{
			ev = malloc(custom_length(environ[k] + 1));
			if (ev == NULL)
			{
				perror("Error allocating memory");
				exit(EXIT_FAILURE);
			}
			custom_concat(ev, environ[k]);
			return (ev);
		}
	}

	return (NULL);
}
