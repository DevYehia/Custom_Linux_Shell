#include <unistd.h>

#include "stringUtil.h"

#define COMMAND_SIZE 1024
#define STDIN 0
#define STDOUT 1
#define STDERR 2

int main(int argc, char* argv[]){
    char command[COMMAND_SIZE];
    int commandIndex = 0;
    char commandChar;

    //shell's infinite loop
    while(1){

        commandIndex = 0;
        //read command character by character till find a newline
        do{
            read(STDIN,&commandChar,1);
            command[commandIndex] = commandChar;
            commandIndex++;
        }while(commandChar != '\n');
        commandIndex = 0;

        //skip starting spaces
        while(command[commandIndex] == ' ')commandIndex++;


        //find out type of command

        //echo command
        if(stringRangeCmp(command, "echo", commandIndex, 4)){

            //skip spaces after the command
            commandIndex+=4;
            while(command[commandIndex] == ' ')commandIndex++;

            while(command[commandIndex] != '\n'){
                write(STDOUT,&command[commandIndex], 1);
                commandIndex++;
            }

            write(STDOUT,&command[commandIndex], 1); //write a newline
        }


    }


}