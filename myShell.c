#include <unistd.h>
#include "utils/stringUtil.h"
#include "defines.h"
#include "commands.h"
#include "utils/printUtil.h"

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

        // echo command
        if (stringRangeCmp(command, "echo", commandIndex))
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
            // list(command + commandIndex);
        }

        else if (stringRangeCmp(command, "whoami", commandIndex))
        {
            print_current_user(envp);
            write(STDOUT, "\n", 1);
        }
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

        for (int i = 0; i < COMMAND_SIZE; i++)
        {
            command[i] = 0;
        }
    }
}
