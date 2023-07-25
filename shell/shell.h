#ifndef HEADER_H
#define HEADER_H
#define _GNU_SOURCE

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>

/* int argument(int argc, char *argv[]);*/
void *_calloc(size_t nmemb, size_t size);
char *_strcat(char *dest, char *src);
int _strcmp(const char *s1, const char *s2);
char *_strcpy(char *dest, const char *src);
size_t _strlen(const char *s);
char **dividestring(char *div_string, char *separator);
char *getenv(const char *name);
void _environ(void);
char *_path(char *cmd_buff);


#endif
