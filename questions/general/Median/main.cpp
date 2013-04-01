/* Sample program illustrating input and output */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool removeValue(vector<int>& vec, int v) {

    if (vec.empty())
        return false;

    for (int i = 0; i < vec.size(); i++) {
        if (v == (int)vec[i]) {
            vec.erase(vec.begin()+i);
            return (vec.empty()) ? false : true;
        }
    }

    return false;
}

int getMedianFromVector(vector<int>& vec) {

    std::sort(vec.begin(), vec.end());

    int len = vec.size();
    if (len % 2 == 0) {
        long long sum = (long long)vec[len/2-1] + (long long)vec[len/2];
        if (sum % 2) 
            cout << (int)(sum/2) << ".5" << endl;
        else
            cout << (int)(sum/2) << endl;
    }
    else
        cout << vec[len/2] << endl;
}

int main() {

    int N;
    cin >> N;

    string s[N];   
    int x[N];

    for(int i = 0; i < N; i++){
        cin >> s[i] >> x[i];
    }

    // start
    vector<int> arr;
    string str_a = "a";
    string str_r = "r";

    for (int i = 0; i < N; i++) {
        if (s[i] == str_a) {
            arr.push_back(x[i]);
            getMedianFromVector(arr);
        } else if (s[i] == str_r) {
            if ( removeValue(arr, x[i]) )
                getMedianFromVector(arr);
            else 
                cout << "Wrong!" << endl;
        }
    }

    return 0;
}

