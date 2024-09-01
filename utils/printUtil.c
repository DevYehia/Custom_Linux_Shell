#include "printUtil.h"

// stop printing when encountring '\0'
void myPrintfMagenta(char *text)
{
    makeTextMagenta();
    while (*text != '\0')
    {
        write(STDOUT, text, 1);
        text++;
    }
    makeTextWhite();
}

// stop printing when encountring '\0'
void myPrintfWhite(char *text)
{
    makeTextWhite();
    while (*text != '\0')
    {
        write(STDOUT, text, 1);
        text++;
    }
}

void myPrintfBlank(char *text)
{
    while (*text != '\0')
    {
        write(STDOUT, text, 1);
        text++;
    }
}

void makeTextMagenta(void)
{
    write(STDOUT, "\e[0;95m", sizeof("\e[0;95m"));
}

void makeTextWhite(void)
{
    write(STDOUT, "\e[0m", sizeof("\e[0m"));
}