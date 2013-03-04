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
    output(p);
}

int main(int argc, char *argv[])
{
    if (argc > 1)
        return foo(argv[1]);
}
