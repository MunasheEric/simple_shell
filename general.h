#ifndef GENERAL_H
#define GENERAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Maximum length for a command*/
#define MAX_COMMAND_LENGTH 1024

/* Function to read a line from stdin*/
char* read_line(void);

/* Function to parse the line into arguments*/
char** parse_line(char* line);

/* Function to execute the command*/
int execute_command(char** args);

#endif /* GENERAL_H*/

