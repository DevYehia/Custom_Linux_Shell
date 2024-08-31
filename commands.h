#ifndef COMMANDS
#define COMMANDS

#include "defines.h"
#include "stringUtil.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <fcntl.h>
#include <dirent.h>

struct linux_dirent {
        unsigned long  d_ino;
        off_t          d_off;
        unsigned short d_reclen;
        char           d_name[];
};


void echo(char *text);
void print_working_directory(char *env_vars[]);
void list(char *path);

#endif