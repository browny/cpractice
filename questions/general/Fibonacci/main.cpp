#include <iostream>

using namespace std;

int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fib(n - 1) + fib (n -2);
}

int fib_loop(int n)
{
    int n_1 = 1, n_2 = 0, fib = 0;
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    for (int i = 2; i <= n ; i++) {
        fib = n_1 + n_2 ;
        n_2 = n_1;
        n_1 = fib;
    }
    return fib;
}
int main(int argc, char** atgv)
{
    int n = 10;
    cout << "fib n = " << n << " result = " << fib_loop(n) << endl;
}
