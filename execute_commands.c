#include "shell.h"

/**
  * execute_commands - This func handles the execution of built-in commands
  * @user_tokens: An array of tokens representing the user's input.
  * @input_line: The input line.
  *
  * Return: it will return 1 if the command is in the supportdcmd or 0.
  */
int execute_commands(char **user_tokens, char *input_line)
{
	int i = 0;
	char *supportedCmd[] = { "exit", "cd", "help", "env", NULL };

	do {
		if (custom_compare(user_tokens[0], supportedCmd[i]) == 0)
		{
			if (i == 0)
			{
				custom_exit_handler(user_tokens, input_line);
			}
			else if (i == 1)
			{
				chdir(user_tokens[1]);
				return (1);
			}
			else if (i == 2)
			{
				open_help_menu();
				return (1);
			}
			else if (i == 3)
			{
				custom_print_environment();
				return (1);
			}
		}
		i++;
	} while (supportedCmd[i]);

	return (0);
}
