#include <iostream>
#include <cmath>
using namespace std;

/*
int getIntergerComplement(int n)
{
    int tmp = n;
    int len = 0;

    while (tmp > 0) {
        tmp >>= 1;
        len++;
    }

    return (((2 << (len-1)) - 1) ^ n);
}
*/


int getIntergerComplement(int n)
{
    int len = 0, tmp = n;

    if (tmp == 0)
        return 1;

    while (tmp > 0) {
        len++;
        tmp >>= 1;
    }

    int two_com = (1 << len) - n;
    return two_com - 1;
}

int main(int argc, char** argv)
{
    int n = 0;
    cin >> n;
    cout << getIntergerComplement(n) << endl;
}
