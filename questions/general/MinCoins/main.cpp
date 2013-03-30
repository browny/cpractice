
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int minCoins(vector<int> a, int sum) {

	int ret;
	for (int i = 0; i < a.size(); i++) {
		int remains = sum - a[i];
		//cout << sum << " - " << a[i] << " = " << remains << endl;
		if (remains > 0) {
			ret = minCoins(a, remains);
			//cout << "ret: " << ret << endl;
			if (ret > 0) {
				cout << a[i] << " + ";
				return ++ret;
			}
		} else if (remains == 0) {
			cout << a[i] << " + ";
			return 1;
		}
	}
	return -1;
}

int main() {

	// Input to a sorted vector
	int size, sum;
	cin >> size >> sum;

	int* arr;
	arr = new int[size];

	for (int i = 0; i < size; i++) {
		int c;
		cin >> c;
		arr[i] = c;
	}
	vector<int> vecArr(arr, arr+size);
	sort(vecArr.begin(), vecArr.end(), greater<int>()); // sorted in descending order
	vecArr.erase( unique(vecArr.begin(), vecArr.end()), vecArr.end() ); // remove duplicates

	// Output
	int out = minCoins(vecArr, sum);
	cout << endl;
	if (out > 0)
		cout << "Minimum " << out << " coins needed" << endl;
	else
		cout << "Impossible" << endl;

	delete[] arr;

	return 0;
}
