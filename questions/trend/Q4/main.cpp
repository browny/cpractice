// Q4: Which one is correct?

#include <stdio.h>

int main(int argc, char** argv)
{
	//A sizeof is an operator
	//int a = new sizeof(int * 20);

	//B
	//int a = new int[20];

	//C
	//int a = new int(20);

	//D
	//int *a = new sizeof(int * 20);

	//E
	int *a = new int[20];

	//F
	//int * a = new 20;

	return 0;
}
