#ifndef COMMANDS
#define COMMANDS

#include "defines.h"
#include "stringUtil.h"
#include "printUtil.h"
#include <unistd.h>




void echo(char *text);
void print_working_directory(char *env_vars[]);
void print_current_user(char* env_vars[]);

#endif