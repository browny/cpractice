#include "Heap.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

Heap::Heap() : mSize(10), mHeap(NULL)
{
    init_heap();
}

Heap::Heap(int size) : mSize(size), mHeap(NULL)
{
    init_heap();
}

Heap::~Heap()
{
    delete [] mHeap;
}

void Heap::Heapify(int i, int size)
{
    int l_child = i * 2;
    int r_child = i * 2 + 1;
    if (l_child > size)
        return;
    if (mHeap[l_child] > mHeap[i]) {
        //cout << "swap(" << i << ", " << l_child
        //<< ") = (" << mHeap[l_child] << ", " << mHeap[i] << ")" <<  endl;
        swap(mHeap[l_child], mHeap[i]);
        Heapify(l_child, size);
    }
    if (r_child > size)
        return;
    if (mHeap[r_child] > mHeap[i]) {
        //cout << "swap(" << i << ", " << r_child
        //<< ") = (" << mHeap[r_child] << ", " << mHeap[i] << ")" << endl;
        swap(mHeap[r_child], mHeap[i]);
        Heapify(r_child, size);
    }
}

void Heap::Heapify(int i)
{
    Heapify(i, mSize);
}

void Heap::HeapSort()
{
    int n = mSize - 1;
    while (n > 1) {
        swap(mHeap[1], mHeap[n]);
        n--;
        Heapify(1, n);
    }

}

void Heap::init_heap()
{
    srand(time(NULL));
    mHeap = new int[mSize];
    mHeap[0] = -1;
    for (int i = 1; i < mSize; i++)
        mHeap[i] = (rand()%100) + 1;
    cout << "Before Heapify " << endl;
    dump();
}

int Heap::getSize()
{
    return mSize;
}

void Heap::dump()
{
    cout << "==== Heap Dump ====" << endl;
    for (int i = 1; i < mSize; i++)
        cout << mHeap[i] << " ";
    cout << endl;

}

int main(int argc, char** argv)
{
    Heap *heap = new Heap(11);

    for (int i = heap->getSize() / 2; i > 0; i--)
        heap->Heapify(i);
    cout << "After Heapify " << endl;
    heap->dump();

    cout<< "=== Heap Sort ===" << endl;
    heap->HeapSort();
    heap->dump();

    delete heap;
    return 0;
}
