#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

static int count_fc = 0;
static int SIZE = 0;
static int count_cache = 0;

int knapsack(int *p, int *v, int n, int aW)
{
    count_fc++;

    if (n == 0 || aW < 0)
        return 0;
    
    int without_taken = knapsack(p, v, n - 1, aW);
    if (p[n - 1] > aW)
        return without_taken;
    int taken = v[n - 1] + knapsack(p, v, n - 1, aW - p[n - 1]);
    return max(without_taken, taken);
}

int cache_knapsack(int *p, int *v, int n, int aW, int *cache)
{
    count_cache++;
    int index = SIZE * (n - 1) + aW;
    if (n == 0 || aW < 0)
        return 0;

    //cout << "index = " << index << " cache[index] = " << cache[index] << endl;
    if (cache[index] != -1) {
        return cache[index];
    }
    
    int without_taken = cache_knapsack(p, v, n - 1, aW, cache);
    if (p[n -1] > aW) {
        cache[index] = without_taken;
        return without_taken;
    }
    int taken = v[n - 1] + cache_knapsack(p, v, n - 1, aW - p[n - 1], cache);
    int max_value = max(without_taken, taken);
    cache[index] = max_value;
    return max_value;
}

int main(int argc, char **argv)
{
    int V[] = { 60, 100, 120};
    int P[] = { 10, 20, 30};
    int maxP = 50;
    int size = sizeof(P) / sizeof(int);
    SIZE = size;
    int max = knapsack(P, V, size, maxP);
    cout << "MAX = " << max << " function call count = " << count_fc << endl;
    
    int memo[3 * 50];
    memset(memo, -1, sizeof(memo));
    max = cache_knapsack(P, V, size, maxP, memo);
    cout << "MAX = " << max << " cache function call count = " << count_cache << endl;
}
