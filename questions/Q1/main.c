// Q1: Please identify the errors or what can be improved?

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void output(const char *pszInput)
{
	// Impro.1: the output func. should only do output work
	// Impro.2: the size of szBuffer is hardcoded
    char szBuffer[1024];
    if (pszInput)
        strcpy(szBuffer, pszInput);
    printf("Your parmeter is \"%s\"\r\n", szBuffer);
}

void foo(const char *pszInput)
{
	// Error1: The terminating '\0' is not counted with strlen()
	// if sizeof(pszInput) is used, it will return "the sizeof pointer"
    char *p = malloc(strlen(pszInput)); // Wrong
	// char *p = malloc((strlen(pszInput) + 1) * sizeof(char));
    output(p);
	// Error2: forget to free
	// free(p);
}

int main(int argc, char *argv[])
{
    if (argc > 1)
        return foo(argv[1]);
}
