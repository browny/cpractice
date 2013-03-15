
#include <iostream>
using namespace std;

int main()
{
	int year;
	cout << "Please enter a year:" << endl;
	while (cin >> year) {
		if( (year%4 == 0) && ( year%100 != 0))
			cout << "year " << year << " is leap year" << endl;
		else if((year%400==0) && (year%100==0))
			cout << "year " << year << " is leap year" << endl;
		else
			cout << "year" << year << " is not leap year" << endl;
	}

	return 0;
}
