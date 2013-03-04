#include <iostream>

//O(n)

using namespace std;

unsigned int remove_duplicated(int *p, unsigned nItem)
{
    int index[1024] = {0};
    int count = 0;
    for (int i = 0; i < nItem; i++) {
        if (index[p[i]] == 0)
            p[count] = p[i];
            count++;
            index[p[i]] = 1;
        }
    }
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
    unsigned  n = remove_duplicated(p, 8);
    cout << "After remove_duplicated";
    dump(p, n);
    count << endl;
}
