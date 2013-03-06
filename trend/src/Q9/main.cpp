#include "Node.h"
#include <iostream>

#define MAX(a, b) a > b ? a : b

using namespace std;

BinaryTree::BinaryTree() : mRoot(NULL), n(1000)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        insert(&mRoot, rand() % 1000);
}

BinaryTree::BinaryTree(int num) : mRoot(NULL), n(num)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        insert(&mRoot, rand() % 50);
}

BinaryTree::~BinaryTree()
{
    destroy(&mRoot);
}

void BinaryTree::print()
{
    cout << "Tree traversal ";
    preorder(&mRoot);
    cout << endl;
}

bool BinaryTree::insert(Node **root, int value)
{
    if (!*root) {
        *root = (Node *) malloc(sizeof(Node));
        (*root)->left = NULL;
        (*root)->right = NULL;
        (*root)->data = value;
        return true;
    }
    if (value > (*root)->data)
        insert(&(*root)->right, value);
    else
        insert(&(*root)->left, value);
    return true;
}

void BinaryTree::preorder(Node **node)
{
    if (!*node)
        return;
    cout << " "<<(*node)->data;
    if ((*node)->left)
        preorder(&(*node)->left);
    if ((*node)->right)
        preorder(&(*node)->right);
}

int BinaryTree::maxlevel(Node **node)
{
    if(*node)
        return MAX(maxlevel(&(*node)->left), maxlevel(&(*node)->right)) + 1;
    else
        return 0;
}

int BinaryTree::height()
{
    mMaxLevel = maxlevel(&mRoot);
    return mMaxLevel;
}


void BinaryTree::destroy(Node **node)
{
    if (!*node)
        return;
    if ((*node)->left)
        destroy(&(*node)->left);
    if ((*node)->right)
        destroy(&(*node)->right);
    free(node);
}

int main(int argc, char** argv)
{
    BinaryTree *tree = new BinaryTree;
    tree->print();
    cout << "Max height "<< tree->height() <<endl;
}
