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

#endif
