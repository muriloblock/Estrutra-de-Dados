#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* createNode(int data){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void appendNode(struct Node** headRef, int data){
	struct Node* newNode = createNode(data);
	if(*headRef == NULL){
		*headRef = newNode;
		return;
	}
	struct Node* tempNode = *headRef;
	while(tempNode->next != NULL){
		tempNode = tempNode->next;
	}
	tempNode->next = newNode;
}

void printList(struct Node* head){
	struct Node* tempNode = head;
	while(tempNode != NULL){
		printf("%d\n", tempNode->data);
		tempNode = tempNode->next;
	}
}

void freeList(struct Node* head){
	struct Node* temp;
	while(head != NULL){
		temp = head;
		head = head->next;
		free(temp);
	}
}

void main(){
	struct Node* head = NULL;

	appendNode(&head, 10);
	appendNode(&head, 20);
	appendNode(&head, 30);

	printList(head);

	freeList(head);
}


