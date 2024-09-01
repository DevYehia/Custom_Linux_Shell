#include "envUtil.h"

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