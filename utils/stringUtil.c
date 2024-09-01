#include "stringUtil.h"

int stringRangeCmp(char *str_one, char *str_two, int str_one_start_index)
{
    int i, j;
    for (i = str_one_start_index, j = 0; str_two[j] != '\0' && str_one[i] != '\0'; i++, j++)
    {
        if (str_one[i] != str_two[j])
        { // mismatch
            return 0;
        }
    }

    if (str_two[j] != '\0')
    {
        return 0;
    }

    // string match
    return 1;
}

void skip_spaces(int *commandIndex, char *command, int command_length)
{
    *commandIndex += command_length;
    while (command[*commandIndex] == ' ')
        (*commandIndex)++;
}
