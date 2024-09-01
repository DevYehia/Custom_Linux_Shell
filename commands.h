#ifndef COMMANDS
#define COMMANDS

#include "defines.h"
#include "utils/stringUtil.h"
#include "utils/printUtil.h"
#include "utils/envUtil.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

#include <stdio.h>

void echo(char *text);
void print_working_directory(char *env_vars[]);
void print_current_user(char *env_vars[]);
void meow(char *file_path);

#endif