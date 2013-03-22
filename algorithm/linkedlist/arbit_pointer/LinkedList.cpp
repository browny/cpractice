#include "LinkedList.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

#define RANDOM (rand() % 100) + 1

LinkedList::LinkedList() : mSize(5), mRoot(NULL), mCopy(NULL)
{
    createList();
    assignRandom();
}

LinkedList::LinkedList(int n) : mSize(n), mRoot(NULL), mCopy(NULL)
{
    createList();
    assignRandom();
}

LinkedList::~LinkedList()
{
    destroyList();
}

void LinkedList::createList()
{
    Node *root = NULL;
    srand(time(NULL));
    mRoot = new Node;
    mRoot->data = RANDOM;
    mRoot->next = NULL;
    mRoot->arbit = NULL;
    vec.push_back(mRoot);
    root = mRoot;
    for (int i = 0; i < mSize - 1; i++) {
        Node *tmp = new Node;
        vec.push_back(tmp);
        tmp->data = RANDOM;
        tmp->arbit = NULL;
        root->next = tmp;
        root = root->next;
    }
}

void LinkedList::destroyList()
{
    while (mRoot) {
        delete mRoot;
        mRoot = mRoot->next;
    }

    while (mCopy) {
        delete mCopy;
        mCopy = mCopy->next;
    }

}

void LinkedList::assignRandom()
{
    int sum[mSize];
    for (int i = 0; i < mSize; i++) {
        sum[i] = i;
    }

    for (int i = 0; i < 100; i++) {
        int index_1 = rand() % mSize;
        int index_2 = rand() % mSize;
        //cout << "index_1 = " << index_1 << " index_2 = " << index_2 << " sum[index_1] = " << sum[index_1]
        //<< " sum[index_2] = " << sum[index_2] << endl;
        swap(sum[index_1], sum[index_2]);
    }
    for (int i = 0; i < mSize; i++) {
        vec[i]->arbit = vec[sum[i]];
    }
}

void LinkedList::printList(bool isArbit)
{
    printList(mRoot, isArbit);
}

void LinkedList::printList(Node *root, bool isArbit)
{
    if (!isArbit) {
        while(root) {
            cout << root->data << " ";
            root = root->next;
        }
    }
    else {
        for (int i = 0; i < mSize; i++) {
            cout << root->arbit->data << " ";
            root = root->next;
        }

    }
    cout << endl;
}

Node* LinkedList::copy()
{
    Node *root = mRoot;
    while (root) {
        Node *tmp = new Node;
        tmp->data = root->data;
        tmp->arbit = NULL;
        tmp->next = root->next;
        root->next = tmp;
        root = tmp->next;
    }

    root = mRoot;

    while (root) {
        root->next->arbit = root->arbit->next;
        root = root->next->next;
    }

    root = mRoot;
    Node *copy = mRoot->next;
    Node *newHead = mRoot->next;
    while (root) {
        root->next = root->next->next;
        root = root->next;
        if (copy && copy->next) {
            copy->next = copy->next->next;
            copy = copy->next;
        }
    }
    mCopy = newHead;
    return mCopy;
}


int main(int argc, char **argv)
{
    LinkedList *list = new LinkedList;
    cout << "print ori" << endl;
    list->printList();
    cout << "print arbit" << endl;
    list->printList(true);
    cout << "print copy arbit" << endl;
    list->printList(list->copy(), true);
    cout << "print copy ori" << endl;
    list->printList(list->copy(), false);
    cout << "print ori" << endl;
    list->printList();
    delete list;
}
