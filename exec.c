#include "shell.h"

/**
  * merge_path - combine path and name
  * @paname: combined path with pro name
  * @prname: the name of the program
  *
  * Return: A string containing the combined path and program name.
  */
char *merge_path(char *paname, char *prname)
{
	int palength = 0, prlength = 0, msize = 0;

	palength = custom_length(paname);
	prlength = custom_length(prname);
	msize = sizeof(char) * (prlength + palength + 2);
	paname = custom_reallocate(paname, (palength + 1), msize);
	if (!paname)
		return (NULL);

	custom_concat(paname, "/");
	custom_concat(paname, prname);

	return (paname);
}

/**
  * user_find - check if the shell got the command
  * @cn: The name of command in the shell
  *
  * Return: return name whem cmd found, null if not
  */
char *user_find(char *cn)
{
	char *user_env_path = NULL, **user_token = NULL;
	int i, usern_de = 0;
	struct stat sb;

	if (cn)
	{
		if (stat(cn, &sb) != 0 && cn[0] != '/')
		{
			user_env_path = get_environment_variable("PATH");
			usern_de = custom_count_occurrences(user_env_path, ":") + 1;
			user_token = split_string(user_env_path, ":", usern_de);

			for (i = 0; user_token[i]; i++)
			{
					user_token[i] = merge_path(user_token[i], cn);

				if (stat(user_token[i], &sb) == 0)
				{
					free(cn);
					cn = custom_duplicate(user_token[i]);
					free_environment_path(user_env_path);
					array_free_tokens(user_token);

					return (cn);
				}
			}
			free_environment_path(user_env_path);
			array_free_tokens(user_token);
		}
		if (stat(cn, &sb) == 0)
			return (NULL);
	}
	free(cn);
	return (NULL);
}
/**
  * execute - this function used to execute command
  * @cn: the given cmd to perform
  * @op: options
  *
  * Return: return status
  */
int execute(char *cn, char **op)
{
	int pros;
	pid_t chpro;

	chpro = fork();

	if (chpro == -1)
	{
		perror("Failed to create fork");
		return (-1);
	}
	else if (chpro == 0)
	{
		execve(cn, op, environ);
	}
	else
	{
		do {
			waitpid(chpro, &pros, WUNTRACED);
		} while (!(WIFEXITED(pros)) && !(WIFSIGNALED(pros)));
	}
	return (0);
}
