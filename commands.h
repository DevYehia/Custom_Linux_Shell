#ifndef COMMANDS
#define COMMANDS

#include "defines.h"
#include "utils/stringUtil.h"
#include "utils/printUtil.h"
#include "utils/envUtil.h"
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <stdio.h>

void echo(char *text);
void print_working_directory(char *env_vars[]);
void print_current_user(char *env_vars[]);
void meow(char *file_path);
int create_files(char *file_paths);
void list(char* dir_path);

#endif