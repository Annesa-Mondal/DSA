// 1. Write a program to implement a stack data structure using an array.

#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct {
	int top;
	int *data;
	int size;
} STACK;


STACK *createStack(STACK * sp, int size) {
	sp = (STACK*)malloc(sizeof(STACK));
	sp->data = (int *)malloc(size * sizeof(int));
	sp->top = -1;
	sp->size = size;
	printf("\nStack created successfully!");
	return sp;
}

void displayStack(STACK *sp) {

	if (sp->top == -1) {
		printf("Stack Empty!");
	}
	else {
		printf("\nDisplaying Stack: ");
		printf("\n\t\t|     |");
		for (int i = sp->top; i >= 0; i--) {
			printf("\n\t\t| %3d |", sp->data[i]);
		} printf("\n\t\t-------");

	}
}

void peekStack(STACK *sp) {
	if (sp->top == (-1)) {
		printf("\nStack is empty!");
	} else {

		printf("\nTop element is %d", sp->data[sp->top]);
	}
}


STACK *pushStack(STACK *sp, int n) {
	if (sp->top >= MAX) {
		printf("\nStack Overflow!");
	}
	else {
		++(sp->top);
		sp->data[sp->top] = n;
	}
	return sp;
}

STACK *popStack(STACK *sp) {
	int a = sp->data[sp->top];
	int *p = &(sp->data[sp->top]);
	--(sp->top);
	free(p);
	return sp;
}


int main() {
	int n, ch, a;
	STACK *sp;
	while (1) {
		printf("\n---------------MENU-------------");

		printf("\n\t1. Create Stack");
		printf("\n\t2. Display Stack");
		printf("\n\t3. Peek");
		printf("\n\t4. PUSH");
		printf("\n\t5. POP");
		printf("\n\t6. Exit");
		printf("\n\tEnter choice(1-6) : ");

		scanf("%d", &ch);

		switch (ch) {
		case 1: {

			sp = createStack(sp, MAX);
			break;
		}
		case 2: {
			displayStack(sp);
			break;
		}
		case 3: {
			peekStack(sp);
			break;
		}
		case 4: {
			printf("\nEnter value to be pushed : ");
			scanf("%d", &n);
			sp = pushStack(sp, n);
			break;
		}
		case 5: {

			int a = sp->data[sp->top];
			sp = popStack(sp);
			printf("\n%d popped successfully", a);
			break;
		}
		case 6: {
			printf("\nExiting!!!");
			exit(0);
		}
		default: {
			printf("\nWrong choice!!!");
		}

		}
	}
	return 0;
}