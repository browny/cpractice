
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void removeChar(char *str, char garbage) {

	char *src, *dst;
	for (src = dst = str; *src != '\0'; src++) {
		*dst = *src;
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

