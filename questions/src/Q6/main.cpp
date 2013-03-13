// Q6: The following function allocates memory but not release them. 
// Please write the release memory statements

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv)
{
	char *p1 = (char*) malloc(sizeof(char) * 10);
	char *p2 = (char*) malloc(sizeof(char) *100);
	char *p3 = new char[100];
	char *p4 = new char;

	//answer
	free(p1);
	free(p2);
	delete [] p3;
	delete p4;
}
