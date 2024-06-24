#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

typedef struct {
	Node* top;
} Stack;

Stack* createStack() {
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->top = NULL;
	return stack;
}

int isEmpty(Stack* stack) {
	return (stack->top == NULL);
}

void push(Stack* stack, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = stack->top;
	stack->top = newNode;
}

int pop(Stack* stack) {
	if(isEmpty(stack))  {
		printf("Error: Empty stack");
		return -1;
	}

	int data = stack->top->data;
	stack->top = stack->top->next;
	return data;
}


int peek(Stack* stack) {
	if(isEmpty(stack)) {
		printf("Error: Empty stack");
		return -1;
	}
	return stack->top->data;
}

void printStack(Stack* stack) {
	Node* current = stack->top;
	printf("Stack elements: ");
	while(current != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

int main(){
	Stack* stack = createStack();

	push(stack, 10);
	push(stack, 20);
	push(stack, 30);

	printStack(stack);

	printf("Stack top: %d\n", peek(stack));

	printf("Popped element: %d\n", pop(stack));
	printf("Popped element: %d\n", pop(stack));

	printStack(stack);

	printf("Stack top: %d\n", peek(stack));
}



