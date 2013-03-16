#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void output(const char *pszInput)
{
	if (pszInput)
		printf("Your parmeter is \"%s\"\r\n", pszInput);
}

int foo(const char *pszInput)
{
    char *p = malloc((strlen(pszInput) + 1) * sizeof(char));
	if (p) {
		strcpy(p, pszInput);
		output(p);
		free(p);
		return 0;
	} else 
		return -1;
}

int main(int argc, char *argv[])
{
	if (argc > 1) {
		printf("\"%s\" length: %zd \r\n", 
				argv[1], strlen(argv[1]));

		return foo(argv[1]);
	}

	return 0;
}
