#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node;


class BinaryTree {
public:
    BinaryTree();
    BinaryTree(int n);
    ~BinaryTree();
    void print();
    int height();
private:
    bool insert(Node **root, int value);
    void preorder(Node **node);
    int maxlevel(Node **node);
    void destroy(Node **node);
    Node *mRoot;
    int n;
    int mMaxLevel;
};
