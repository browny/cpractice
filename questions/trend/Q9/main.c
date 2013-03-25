#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define max(a,b) (a) > (b) ? (a) : (b)

typedef struct node
{
	int val;
	struct node *left;
	struct node *right;
}mynode;

#define MAX_NODE 8

int maxLevel(mynode *node)
{
	if(node != NULL)
		return max(maxLevel(node->left),maxLevel(node->right)) + 1;
	else
		return 0;
}

void Dump(mynode *root)
{
	if(root != NULL)
		printf("%3d",root->val);

	if(root->left != NULL)
		Dump(root->left);

	if(root->right != NULL)
		Dump(root->right);
}

mynode *Insert(int num, mynode *root)
{
	mynode *leaf = NULL, *current = NULL, *prev = NULL;

	leaf = (mynode *) malloc(sizeof(mynode));
	leaf->val = num;
	leaf->left = NULL;
	leaf->right = NULL;

	if(root == NULL)
		root = leaf;
	else {
		current = root;
		while(current != NULL) {
			prev = current;
			if(num <= current->val)
				current = current->left;
			else
				current = current->right;
		}
		if(num <= prev->val)
			prev->left = leaf;
		else
			prev->right = leaf;
	}
	return root;
}


int main(int argc,char **argv)
{
	int i = 0;
	mynode *root = NULL;

	srand(time(NULL));
	for(i=0;i<MAX_NODE;i++)
		root = Insert(rand()%50+1,root);

	Dump(root);
	printf("\nmaxLevel = %d\n",maxLevel(root));
	return 0;
}
