#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* link;
};

struct Node* head;

static unsigned long listLength = 0;

enum state{
	true=0,
	false,
};


struct Node* createNode(int data){
	
	struct Node* newNode  = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->link = NULL;
	return newNode;
}
// to insert at the end
void insert(int data, int n){
	struct Node* newNode = createNode(data);
	// temp node
	struct Node* temp = head;
	// insert at beginning 
	if(n==0){
		// check if list is Empty;
		if(listLength == 0){
			head = newNode;
		}
		else{
			newNode->link = head;
			head = newNode;
		}
		listLength++;
	}
	else if(n>0){
		int cnt = 0;
		while((cnt!=n) && temp!=NULL){
			temp = temp->link;
		}
		newNode->link = temp->link;
		temp->link = newNode;
		listLength++;
	}
	else{
		printf("Invalid n\n");
	}
}

int deleteNode(int data){
	int retVal;	
	if(head == NULL){
		printf("Linked List Empty");
		retVal = -1;
	}
	else{
		struct Node* current = head;
		struct Node* prev = NULL;
		while(current != NULL){
				if(current->data == data){
						prev->link = current->link;
						free(current);
						retVal = current->data;
						break;
				}
				prev = current;
				current = current->link;
		}
	}
	return retVal;
}




