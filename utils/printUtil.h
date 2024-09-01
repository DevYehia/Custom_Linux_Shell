/*This library is for fancy printing of text*/

#ifndef PRINT_UTIL_H
#define PRINT_UTIL_H

#include <unistd.h>
#include "../defines.h"

void makeTextMagenta(void);
void makeTextWhite(void);
void makeTextRed(void);

void myPrintfBlank(char *text);
void myPrintfWhite(char *text);
void myPrintfRed(char *text);
void myPrintfMagenta(char *text);

#endif