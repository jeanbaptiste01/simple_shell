#include "shell.h"

/**
  * free_environment_path - This func frees the memory used by an env variable.
  * @user_env_path: The environment variable to be freed.
  *
  * Return: No return value.
  */
void free_environment_path(char *user_env_path)
{
	int a = 4;

	do {
		a--;
		user_env_path--;
	} while (a >= 0);
	free(user_env_path);
}

/**
  * array_free_tokens - This func frees the memory used by an array of tokens
  * @custom_tokens: The array of tokens to be freed.
  *
  * Return: Nothing to returns
  */
void array_free_tokens(char **custom_tokens)
{
	char **ptr = custom_tokens;

	if (custom_tokens)
	{
		do {
			free(*custom_tokens++);
		} while (*custom_tokens);
		free(ptr);
	}
}
