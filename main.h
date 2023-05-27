#ifndef MAIN_H

#define MAIN_H

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

#define CMDLINE_MAX_LENGTH 1024

#define MAX_NUM_ARGS 1024

extern char **environ;

char *read_line(void);

char **split_line(char *line);

int execute(char **args);

int launch(char **args);

void sigchld_handler(int sig);

void sigint_handler(int sig);

#endif /* MAIN_H */
