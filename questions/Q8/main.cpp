// Q8: Check if the number is palindrome
// do not use any C/C++ library such as strlen()

// 利用反過來跟原數字相同的概念去解

#include <iostream>

using namespace std;

int reverseNum(int num)
{
	static int pal = 0;
	if (num > 0) {
		pal = (pal * 10) + num % 10;
		reverseNum(num / 10);
	}
	return	pal;
}

int main(int argc, char** argv)
{
	int a;
	cout << "input a number" << endl;
	cin >> a;
	if (reverseNum(a) == a)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}
