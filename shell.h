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
#include <stdbool.h>

/* for read & write buffers */
#define READ_BUFSIZE 1024
#define WRITE_BUFSIZE 1024
#define BUF_FLUSHER -1

/* handle strings print*/
int _putchar(char c);
int _puts(const char *str);
int _put(const char *str);
void print_digits(unsigned int n);
void print(char **av);

/* handle errors print*/
void _eputs(char *str);
int _eputchar(char c);
int _erratoi(char *s);
void print_error(informer_me *info, char *estr);
int print_d(int input, int fd);

/* exit proto*/
int exit(informer_me *info);

/*handles execve*/
void executer(const char *path, char **argv, char **env);

/**
 *struct passinfo - contains pseudo-arguements to pass into a function,
 *              allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@path: a string path for the current command
 *@argc: the argument count
 *@line_count: the error count
 *@err_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@fname: the program filename
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@history: the history node
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read line input
 *@histcount: the history line number count
 */

typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} informer_me;

#endif
