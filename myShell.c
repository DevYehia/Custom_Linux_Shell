#include <unistd.h>
#include "stringUtil.h"
#include "defines.h"
#include "commands.h"
#include "printUtil.h"
int main(int argc, char *argv[], char *envp[])
{
    char command[COMMAND_SIZE];
    int commandIndex = 0;
    char commandChar;

    // shell's infinite loop
    while (1)
    {
        //print current user
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

            // skip spaces after the command
            commandIndex += 4;
            while (command[commandIndex] == ' ')
                commandIndex++;

            char *textStartingPoint = command + commandIndex;
            echo(textStartingPoint);
        }

        // pwd command
        else if (stringRangeCmp(command, "pwd", commandIndex))
        {
            print_working_directory(envp);
        }

        //ls command (TO DOOOOOOOOO)
        else if( stringRangeCmp(command, "ls", commandIndex)){

            //skip ls and spaces
            commandIndex += 2;
            while (command[commandIndex] == ' ')
                commandIndex++;     
            //list(command + commandIndex);       
        }

        else if( stringRangeCmp(command, "whoami", commandIndex)){
            print_current_user(envp);
            write(STDOUT, "\n", 1);
        }
    }
}