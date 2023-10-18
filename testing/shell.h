#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 256
#define PROMPT "(Oluwakuty)$ "

extern char **environ;

FILE *fileOpen(int argc, char *argv[]);
void promptDisplay(FILE *usr_line);
void commandReading(char *command, FILE *usr_line);
void tokenizer(char *command, char *args[]);
void exitHandling(char *args[], FILE *usr_line);
void envHandle(void);
void commandExecution(char *args, char *binDirectory,
		int *statuse, pid_t *process_id);


#endif
