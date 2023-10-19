#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

/**
 * struct bultin - Description
 * @command: string
 * @func: pointer
 */
typedef struct bultin
{
char *command;
void (*func)(char **, int);
} sp_t;

void (*bultin_handler(char *str))(char **, int);
void env_me(char **command, int statuse);
void exit_me(char **str, int statuse);

extern char **environ;

void writePrompt(void);
int _strlen(char *s);
char *_strcpy(char *destination, char *sourcec);
char *_strdup(char *str);
char **inputSplinter(char *spliter);
int count_tokinz(char *usrInput);
int execution(char **command, char **argv);
int _strcmp(char *str1, char *str2);
char *_strcat(char *destination, char *source);
void spaceFree(char **freed);
char *envGetting(char *naming);
char *cmdGetting(char *command);
char *readInput(void);


#endif
