#include "commands.h"

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

void print_current_user(char *env_vars[])
{
    char *currUser = myGetEnv(env_vars, "USER");
    myPrintfBlank(currUser);
}

void meow(char *file_path)
{
    int fd = open(file_path, O_RDONLY);

    char c;
    int bytes_read = read(fd, &c, 1);

    while (bytes_read != 0)
    {
        write(STDOUT, &c, 1);
        bytes_read = read(fd, &c, 1);
    }
}