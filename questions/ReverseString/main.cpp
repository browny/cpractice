
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char* str) {
	char* end = str;
	char tmp;
	if (str) {
		while (*end) { /* find the end of string */
			++end;
		}
		--end; /* back one, because the last 1 is null */

		// swap
		while (str < end) {
			tmp = *str;
			*str++ = *end;
			*end-- = tmp;
		}
	}
}

int main()
{
	char S[] = "ABCDEFG";
	reverse(S);
	printf("reversed: %s", S);
}

