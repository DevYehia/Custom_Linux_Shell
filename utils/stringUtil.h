/*This file contains all custom-made string functions to help in parsing the input*/

#ifndef STRING_UTILS
#define STRING_UTILS

int stringRangeCmp(char *str_one, char *str_two, int str_one_start_index);
void skip_spaces(int *commandIndex, char *command, int command_length);

#endif