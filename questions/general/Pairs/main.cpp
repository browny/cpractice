/*
 *  Given N numbers [N<=10^5], count the total pairs of numbers that have a difference of K. [K>0 and K<1e9].
 *  Each of the N numbers will be > 0 and be less than K away from 2^31-1 (Everything can be done with 32 bit integers).
 *
 *  Sample Input #00:
 *
 *  5 2
 *  1 5 3 4 2
 *
 *  Sample Output #00:
 *
 *  3
 */


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    // Input to a sorted vector
    int size, diff;
    cin >> size >> diff;

    int* arr;
    arr = new int[size];

    for (int i = 0; i < size; i++) {
        int c;
        cin >> c;
        arr[i] = c;
    }
    vector<int> vecArr(arr, arr+size);
    sort(vecArr.begin(), vecArr.end());
    //vecArr.erase( unique(vecArr.begin(), vecArr.end()), vecArr.end() );

    // Get the pair
    int cnt = 0;
    int tmp = 0; // use tmp to avoid repeated computation for the same value
    bool tmpResult = false;

    for (int i = 0; i < vecArr.size() -1; i++) {
        int head = vecArr[i];
        if (head == tmp) {
            // use buffered result
            if (tmpResult == true) {
                cnt++;
            }
        } else {
            tmp = head;
            tmpResult = false;

            for (int j = i+1; j < vecArr.size(); j++) {
                if (vecArr[j] - head > diff)
                    break;
                if (abs(head-vecArr[j]) == diff) {
                    cnt++;
                    tmpResult = true;
                }
            }
        }
    }
    delete[] arr;

    // Output
    cout << cnt << endl;

    return 0;
}
