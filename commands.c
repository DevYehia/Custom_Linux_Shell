#include "commands.h"
#include "defines.h"
#include "stringUtil.h"
#include <unistd.h>

void echo(char *text)
{
    while (*text != '\n')
    {
        write(STDOUT, text, 1);
        text++;
    }

    write(STDOUT, "\n", 1); // write a newline
}

void print_working_directory(char *env_vars[])
{
    char *currDir = myGetEnv(env_vars, "PWD");
    while (*currDir != '\0')
    {
        write(STDOUT, currDir, 1);
        currDir++;
    }

    write(STDOUT, "\n", 1);
}
