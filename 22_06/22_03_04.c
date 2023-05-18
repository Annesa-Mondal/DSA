#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 50

struct Stack {
    int data[MAX_SIZE];
    int top;
};

// Initialize a stack
void initialize(struct Stack *s) {
    s->top = -1;
}

// Check if the stack is empty
bool is_empty(struct Stack *s) {
    return s->top == -1;
}

// Check if the stack is full
bool is_full(struct Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// Push an element onto the stack
void push(struct Stack *s, int value) {
    if (is_full(s)) {
        printf("Error: Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    s->data[++s->top] = value;
}

// Pop an element from the stack
int pop(struct Stack *s) {
    if (is_empty(s)) {
        printf("Error: Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->data[s->top--];
}

// Check if two stacks are equal
bool is_equal(struct Stack *s1, struct Stack *s2) {
    if (s1->top != s2->top) {
        return false;
    }
    for (int i = 0; i <= s1->top; i++) {
        if (s1->data[i] != s2->data[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    struct Stack s1, s2;
    initialize(&s1);
    initialize(&s2);

    int n, value;

    printf("Enter the number of elements for Stack 1: ");
    scanf("%d", &n);

    printf("Enter the elements for Stack 1: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(&s1, value);
    }

    printf("Enter the number of elements for Stack 2: ");
    scanf("%d", &n);

    printf("Enter the elements for Stack 2: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(&s2, value);
    }

    bool result = is_equal(&s1, &s2);

    if (result) {
        printf("The two stacks are equal\n");
    } else {
        printf("The two stacks are not equal\n");
    }

    return 0;
}
