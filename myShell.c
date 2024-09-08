#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "utils/stringUtil.h"
#include "defines.h"
#include "commands.h"
#include "utils/printUtil.h"
#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
    char command[COMMAND_SIZE];
    int commandIndex = 0;
    char commandChar;

    // shell's infinite loop
    while (1)
    {
        // print current user
        makeTextMagenta();
        write(STDOUT, "Quack-", sizeof("Quack-"));
        print_current_user(envp);
        makeTextWhite();
        write(STDOUT, "$ ", 2);

        commandIndex = 0;
        // read command character by character till find a newline
        do
        {
            read(STDIN, &commandChar, 1);
            command[commandIndex] = commandChar;
            commandIndex++;
        } while (commandChar != '\n');
        commandIndex = 0;

        // skip starting spaces
        while (command[commandIndex] == ' ')
            commandIndex++;

        // find out type of command

        //exit out of shell
        if (stringRangeCmp(command, "exit", commandIndex))
        {
            break;
        }

        //echo command
        else if (stringRangeCmp(command, "echo", commandIndex))
        {

            skip_spaces(&commandIndex, command, 4);

            char *textStartingPoint = command + commandIndex;
            echo(textStartingPoint);
        }

        // pwd command
        else if (stringRangeCmp(command, "pwd", commandIndex))
        {
            print_working_directory(envp);
        }

        // ls command (TO DOOOOOOOOO)
        else if (stringRangeCmp(command, "ls", commandIndex))
        {

            skip_spaces(&commandIndex, command, 2);
            char* dirPath = command + commandIndex;

            //replace ending newline with null character
            int tempIndex = 0;
            while(dirPath[tempIndex] != '\n'){
                tempIndex++;
            }            
            dirPath[tempIndex] = '\0';
            list(command + commandIndex);
            write(STDOUT, "\n", 1);
        }

        //get current user (whoami command)
        else if (stringRangeCmp(command, "whoami", commandIndex))
        {
            print_current_user(envp);
            write(STDOUT, "\n", 1);
        }

        //get content of file (meow command)
        else if (stringRangeCmp(command, "meow", commandIndex))
        {
            skip_spaces(&commandIndex, command, 4);

            char *file_path = command + commandIndex;

            int temp = commandIndex;
            while (file_path[temp] != '\n')
            {
                temp++;
            }

            file_path[temp] = '\0';
            meow(file_path);
            write(STDOUT, "\n", 1);
        }

        //create a file (touch command)
        else if (stringRangeCmp(command, "touch", commandIndex))
        {
            skip_spaces(&commandIndex, command, 5);

            //get pointer to files
            char *file_paths = command + commandIndex;
            int file_paths_index = 0;

            //replace newline with null
            while (file_paths[file_paths_index] != '\n')
                {
                    file_paths_index++;
                }
            file_paths[file_paths_index] = '\0';

            
            create_files(file_paths);

            // myPrintfBlank(file_paths);
        }

        // exit command
        else if (stringRangeCmp(command, "out", commandIndex))
        {
            return 0;
        }

        // check for executable
        else
        {

            // make newline to be null character
            while (command[commandIndex] != '\n')
            {
                commandIndex++;
            }
            command[commandIndex] = '\0';

            // check if file exists
            int fd = open(command, O_RDONLY);
            close(fd);
            if (fd != -1)
            { // file exists
                int pid = fork();
                if (pid == 0)
                { // child process
                    char *childArgv[2];
                    childArgv[0] = command;
                    childArgv[1] = 0;
                    execve(command, childArgv, envp);
                    return 0;
                }
                else
                { // parent should wait for child
                    wait(0);
                    write(STDOUT, "\n", 1);
                }
            }
        }

        //clear out command buffer
        for (int i = 0; i < COMMAND_SIZE; i++)
        {
            command[i] = 0;
        }
    }
}
