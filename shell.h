#ifndef _SHELL_
#define _SHELL_

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

extern char **environ;

char *custom_concat(char *target, char *extension);
int custom_length(const char *input);
int custom_compare(char *strA, char *strB);
char *custom_duplicate(char *original);
int custom_convert_to_integer(char *str);
int custom_string_compare(const char *cstr1, const char *cstr2, size_t cn);
int _putchar(char charac);
void _puts(char *strn);
void *custom_reallocate(void *ptr, unsigned int osize, unsigned int nsize);
int custom_count_delimiters(char *wstr, char *occurrences);
int custom_count_words(char *user_input);
char *modify_string(char *input_string);
void handle_custom_signal(int signal_num);
void open_help_menu(void);
void custom_print_environment(void);
void custom_exit_handler(char **user_tokens, char *input_line);
void free_environment_path(char *user_env_path);
void array_free_tokens(char **custom_tokens);
int execute_commands(char **user_tokens, char *input_line);

#endif
