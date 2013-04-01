#include <iostream>
#include <cmath>
using namespace std;

int getIntergerComplement(int n)
{
    int bits[32] = {0};
    int len = 0;

    if (n == 0)
        return 1;

    while (n > 0) {
        bits[len++] = n % 2 ? 0 : 1;
        n >>= 1;
    }

    int result = 0;
    for (int i = len - 1; i >= 0; i--) {
        n = n + bits[i] * pow(2, i);
    }

    return n;
}

int main(int argc, char** argv)
{
    int n = 0;
    cin >> n;
    cout << getIntergerComplement(n) << endl;
}
