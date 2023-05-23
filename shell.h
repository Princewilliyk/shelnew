#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <signal.h>

/* handle strings print*/
int _putchar(char c);
int _puts(const char *str);
int _put(const char *str);
void print_digits(unsigned int n);
void print(char **av);

/*getline function proto*/
ssize_t _getlines(char **lineptr, size_t *n, FILE *stream);

void shprompt(char **av, char **env);

#endif
