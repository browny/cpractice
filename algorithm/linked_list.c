#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};

typedef struct node Node;

Node* Add(Node* list, int data);
Node* Delete(Node* list, int data);
void Dump(Node* list);

int main(int argc, char** argv)
{
	int num[10] = {12,34,22,66,41,87,74,35,22,17};
	int i = 0;
	Node *list = NULL;

	for(i=0; i<10; ++i) {
		list = Add(list,num[i]);
	}
	Dump(list);

	list = Delete(list,12);
	Dump(list);
	list = Delete(list,66);
	Dump(list);
	list = Delete(list,100);
	Dump(list);
	list = Delete(list,1);
	Dump(list);
	list = Delete(list,35);
	Dump(list);
	list = Delete(list,17);
	Dump(list);
	
	return 0;
}

Node* Add(Node* list, int data)
{
	Node* temp = NULL;
	Node* new_n = (Node* )malloc(sizeof(Node));
	new_n->data = data;
	new_n->next = NULL;
	

	if(list == NULL)
		list = new_n;
	else {	
		temp = list;
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = new_n;
	}

	return list;
}

Node* Delete(Node* list, int data)
{
	Node *current,*prev,*next;

	if(list->data == data) {
		current = list;
		list = current->next;
		free(current);
		printf("%3d has been deleted\n",data);	
	} else {
		prev = list;
		current = list->next;
		while(current != NULL) {
			if(current->data == data)
				break;
			prev = current;
			current = current->next;
		}

		if(current != NULL) {
			prev->next = current->next;
			free(current);
			printf("%3d has been deleted\n",data);	
		} else
			printf("%3d not in list\n",data);	
	}

	return list;
}

void Dump(Node* list)
{
	Node* temp = list;
	while(temp != NULL) {
		printf("%3d->",temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

