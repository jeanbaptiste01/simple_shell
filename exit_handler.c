#include "shell.h"

/**
  * custom_exit_handler -This function handles the exit command.
  * @user_tokens: -It takes an array of custom tokens and
  * the input line as arguments.
  * If the exit status is provided and valid, it exits with that status.
  * @input_line: -If no exit status is provided or
  * it's invalid, it exits with a default status of 2.
  *
  * Return: No return value.
  */
void custom_exit_handler(char **user_tokens, char *input_line)
{
	int exit_code = 0;

	if (user_tokens[1] == NULL ||
		custom_convert_to_integer(user_tokens[1]) == 0)
	{
		array_free_tokens(user_tokens);
		free(input_line);
		exit(0);
	}

	exit_code = custom_convert_to_integer(user_tokens[1]);
	if (!(exit_code == 0))
	{
		array_free_tokens(user_tokens);
		free(input_line);
		exit(exit_code);
	}
	else
	{
		_puts("Error: Invalid exit status: ");
		_puts(user_tokens[1]);
		_puts("\n");
		exit(2);
	}

	array_free_tokens(user_tokens);
	free(input_line);
	exit(EXIT_SUCCESS);
}
