
#include <string>
#include <iostream>

using namespace std;

int main()
{
	string mainString, subString;

	cout << "enter a string" << endl;
	getline (cin, mainString);

	cout << "enter a word to be removed" << endl;
	getline (cin, subString);

	cout << "the removed string:" << endl;

	for (int i = 0; i < mainString.length(); ++i) {
		int mp = i;
		int sp = 0;
		while (mainString[mp] == subString[sp] &&
				sp < subString.length() && mp < mainString.length()) {
			mp++;
			sp++;
		}
		if (sp < subString.length())
			cout << mainString[i];
		else
			i = i + sp - 1;
	}
	cout << endl;

	return 0;
}

