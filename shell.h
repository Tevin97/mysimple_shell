#ifndef SHELL_H
#define SHELL_H

/* Useful Libaries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* Extern Variables */
extern char **environ;

/* Function Prototypes */
char *prompt(void);
int exec(char **argv);
char **str_to_array(char *str, char *delim);
int fork_and_execute(char *command, char *prog_name, int line_nr);
char *_getenv(const char *name);
char **path(void);
char *concat_str(const char *s1, const char *s2);
int check_stat(char **filename);
void print_message(char *prog_name, int line_nr, char *command, int err_stat);
char *_itoa(unsigned int n);

#endif /* SHELL_H */
