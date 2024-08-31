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
#include <stdio.h>
void list(char *path){
    printf("Hello\n");
    int dirFd = openat(AT_FDCWD, path, O_RDONLY|O_NONBLOCK|O_DIRECTORY|O_CLOEXEC);
    struct linux_dirent dirInfo;
    int bytesRead = syscall(SYS_getdents, dirFd, &dirInfo,  32768);
    //while(bytesRead != 0){
        printf("Read %d bytes: %s\n",bytesRead, dirInfo.d_name);
        bytesRead = syscall(SYS_getdents, dirFd, &dirInfo,  32768);
    //}
    

    printf("%d\n", dirFd);
}