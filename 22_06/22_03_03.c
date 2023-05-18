#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

typedef struct node {
	int data;
	struct node* link;
} Node;

typedef struct {
	Node *top;
} Stack;

Node *createNode(int data) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->link = NULL;

	return newNode;
}

Stack *createStack() {
	Stack *stack  = (Stack*)malloc(sizeof(Stack));
	stack->top = NULL;
	return stack;
}

void push(Stack *s, int data) {
	Node *newNode = createNode(data);
	if (!newNode) {
		printf("[-]OVERFLOW");
	}
	if (s->top == NULL) {
		s->top = newNode;
	} else {

		newNode->link = s->top;
		s->top = newNode;
	}
}

void pop(Stack *s) {

	if (!s->top) {
		printf("[-]EMPTY STACK[UNDERFLOW]\n");
		return;
	} else {
		s->top = s->top->link;
	}
}

int peek(Stack *s) {
	if (!s->top) {
		printf("[-]EMPTY STACK[UNDERFLOW]\n");
		return INT_MIN;
	} else {
		return s->top->data;
	}
}
int isEmpty(Stack *s) {
	return s->top == NULL;
}

void display(Stack *s) {
	printf("[+]Stack\n_________\n");
	Node *temp = s->top;

	while (temp) {
		printf("\t%d\n_________\n", temp->data);
		temp = temp->link;
	}
}

int main()
{


	FILE *fp = fopen("file3.txt", "r");
	Stack *s  = createStack();
	int num;
	while (fscanf(fp, "%d", &num) != EOF) {
		push(s, num);
	}

	printf("REVERSE ORDER: ");
	while (!isEmpty(s)) {
		printf("%d ", peek(s));
		pop(s);
	}




	return 0;
}
