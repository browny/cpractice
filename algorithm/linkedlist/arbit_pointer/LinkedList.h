#include <iostream>
#include <vector>
using namespace std;

struct _Node {
	int data;
	struct _Node *next;
	struct _Node *arbit;
};

typedef _Node Node;

class LinkedList {
public:
	LinkedList();
	LinkedList(int);
	~LinkedList();
	void printList(bool isArbit = 0);
	void printList(Node *root, bool isArbit = 0);
	struct _Node* copy();

private:
	void createList();
	void destroyList();
	void assignRandom();
	Node *mRoot;
	Node *mCopyRoot;
	int mSize;
	vector<Node *> vec;
};
