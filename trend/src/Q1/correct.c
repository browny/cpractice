#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void output(const char *pszInput)
{
    char szBuffer[1024];
    if (pszInput)
        strcpy(szBuffer, pszInput);
    printf("Your parmeter is \"%s\"\r\n", szBuffer);
}

void foo(const char *pszInput)
{
    char *p = malloc(strlen(pszInput));
    //we don't want to print a null string.
    //output(p);
    output(pszInput);
}

int main(int argc, char *argv[])
{
    if (argc > 1)
    //foo in a non-returned function.
    //  return foo(argv[1]);
        foo(argv[1]);
    return 0;
}
