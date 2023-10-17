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

#define READ_BUF_SIZE 1024

void ola_print(const char *mssg);
void env_print(char **env);
int forwardSlash(const char *string);
char *getLocation(char *file_name);
void ola_printOut(const char *mssg, ...);
int _getLine(ino_t *formation, char **pointer, size_t *length);
ssize_t buffer_reading(ino_t formation, char *buffs, ino_t sizebuf);
void exit_handling(char **arr);
void setEnvVar(char **arr);
void unsetEnvVar(char **arr);

#endif
