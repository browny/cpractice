#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define DEBUG 0

// greedy
int minCoins_greedy(vector<int> a, int sum) {

    sort(a.begin(), a.end(), greater<int>()); // sorted in descending order
    a.erase(unique(a.begin(), a.end()), a.end()); // remove duplicates

    int ret;
    for (int i = 0; i < a.size(); i++) {
        int remains = sum - a[i];
        //cout << sum << " - " << a[i] << " = " << remains << endl;
        if (remains > 0) {
            ret = minCoins_greedy(a, remains);
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

int minCoins(vector<int> S, int sum) {

    int setSize = S.size();
    int count[setSize + 1][sum + 1];

    /*
     * cost func:
     * c(n, sum): 用第1種到第n種錢幣湊得價位sum，最少所需要的錢幣數
     * c(n, sum) = min( c(n-1, sum) , c(n, sum-S[n]) + 1 )
     *                ^^^^^^^^^   ^^^^^^^^^^^^^^^^
     *                don't take     take S[n]
     */

    // For sum = 0, do not need any coins
    for (int i = 0; i < setSize + 1; i++)
        count[i][0] = 0;

    // For empty set, it is impossible to sum to >0
    // use -1 represents fail
    for (int j = 1; j < sum + 1; j++)
        count[0][j] = 0xffff;

    //To make sure count[0][0] = 0
    count[0][0] = 0;

    for (int i = 1; i < setSize + 1; i++) {
        for (int j = 1; j < sum + 1; j++) {
            int cur_sum = j;
            int cur_coin = S[i - 1];
            int diff = cur_sum - cur_coin;
            if (diff >= 0) {
                count[i][j] = min(count[i - 1][j], count[i][diff] + 1);
            }
            else
                count[i][j] = count[i - 1][j];
        }
    }

#if DEBUG
    // uncomment this code to print table
    for (int i = 0; i <= setSize; i++)
    {
        for (int j = 0; j <= sum; j++)
            printf ("%4d", count[i][j]);
        printf("\n");
    }
#endif

    if (count[setSize][sum] == 0xffff)
        return -1;
    else
        return count[setSize][sum];
}


int main() {

    // Input to a sorted vector
    int size, sum;
    cout << "input 'size' and 'sum'" << endl;
    cout << "ex: 4 63" << endl;
    cin >> size >> sum;

    cout << "input coins" << endl;
    cout << "ex: 1 10 30 40" << endl;

    int* arr;
    arr = new int[size];
    for (int i = 0; i < size; i++) {
        int c;
        cin >> c;
        arr[i] = c;
    }
    vector<int> vecArr(arr, arr+size);

    // Output
    int out = minCoins(vecArr, sum);
    //int out = minCoins_greedy(vecArr, sum);

    cout << endl;
    if (out > 0)
        cout << "Minimum " << out << " coins needed" << endl;
    else
        cout << "Impossible" << endl;

    delete[] arr;

    return 0;
}
