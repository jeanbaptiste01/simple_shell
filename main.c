#include "shell.h"

/**
 * main - The main function that serves as the entry point to the Shell.
 *
 * Return: Always returns zero.
 */

int main(void)
{
	char *user_input = NULL, **user_tokens = NULL;
	int word_count = 0, execution_flag = 0;
	size_t input_size = 0;
	ssize_t input_length = 0;

	do {
		signal(SIGINT, handle_custom_signal);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);
		input_length = getline(&user_input, &input_size, stdin);
		if (input_length == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		word_count = custom_count_words(user_input);
		if (user_input[0] != '\n' && word_count > 0)
		{
			user_tokens = split_string(user_input, " \t", word_count);
			execution_flag = execute_commands(user_tokens, user_input);
			if (!execution_flag)
			{
				user_tokens[0] = user_find(user_tokens[0]);
				if (user_tokens[0] && access(user_tokens[0], X_OK) == 0)
					execute(user_tokens[0], user_tokens);
				else
					perror("./hsh");
			}

			array_free_tokens(user_tokens);
		}
	} while (input_length >= 0);

	free(user_input);
	return (0);
}
