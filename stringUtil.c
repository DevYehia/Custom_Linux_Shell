
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

char *myGetEnv(char *envp[], char *envName)
{
    for (int i = 0; envp[i] != 0; i++)
    {
        // PWD=sldsdsl
        if (stringRangeCmp(envp[i], envName, 0))
        {

            char *envPtr = envp[i];
            // move pointer to after envName
            while (*envName != '\0')
            {
                envName++;
                envPtr++;
            }

            return ++envPtr; //++ due to = sign
        }
    }
}