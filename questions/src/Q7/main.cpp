// Q7: Write an efficient program to remove duplicate values from a sorted
// ascending array. For example, if input array is p = {1,1,3,5,8,8,10,10},
// nItem = 8. After executing the function, function return 5, and p becomes
// {1,3,5,8,10}

#include <iostream>
#include <string.h>
//O(n)

using namespace std;

void resize(int *p, unsigned n)
{
    int *arr = new int[n];
    memcpy(arr, p, n * sizeof(int));
    p = arr;
}

unsigned int remove_duplicated_2(int *p, unsigned nItem)
{
    int k = 0;
    for (int i = 1; i < nItem; i++) {
        if (p[k] != p[i]) {
            p[k + 1] = p[i];
            k++;
        }
    }

    return k + 1;
}

unsigned int remove_duplicated(int *p, unsigned nItem)
{
    int index[1024] = {0};
    int count = 0;
    for (int i = 0; i < nItem; i++) {
        if (index[p[i]] == 0) {
            p[count] = p[i];
            count++;
            index[p[i]] = 1;
        }
    }
    resize(p, count);
    return count;
}

void dump(int *p, unsigned n)
{
    for (int i = 0; i < n ; i++) {
        cout<<p[i]<<" ";
    }
}

int main(int argc, char** argv)
{
    int p[]  = {1, 1, 3, 5, 8, 8, 10, 10};
    unsigned  n = remove_duplicated_2(p, sizeof(p)/sizeof(int));
    cout << "After remove_duplicated size " << n << " "<< endl;
    dump(p, n);
    cout << endl;
}
