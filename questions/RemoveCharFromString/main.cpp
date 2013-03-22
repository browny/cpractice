
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void removeChar(char *str, char garbage) {

	char *dst;
	for (dst = str; *str!= '\0'; str++) {
		*dst = *str;
		if (*dst != garbage) dst++;
	}
	*dst = '\0';
}

int main()
{
	char in[] = "abcdef";
	char* str = (char*)malloc(strlen(in) + 1);
	strcpy(str, in);
	removeChar(str, 'b');
	printf("%s", str);
	free(str);

	return 0;
}
