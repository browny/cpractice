
class Heap {
public:
    Heap();
    Heap(int size);
    ~Heap();
    void Heapify(int);
    void Heapify(int, int);
    void HeapSort();
    void dump();
    int getSize();

private:
    void init_heap();
    int *mHeap;
    const int mSize;
};
