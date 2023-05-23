#ifndef MAIN_H

#define MAIN_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ERROR_LENGTH (MAX_COMMAND_LENGTH + 30)

void mainPrompt(void);
void printPrompt(void);
int executeCommand(char *command);
void handleInputError(const char *command);
int isInteractiveMode(void);
void processInteractiveInput(void);
void processNonInteractiveInput(void);
extern char **environ;

#endif /* MAIN_H */
