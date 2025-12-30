#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum size of the stack

// Global variables
int stack[MAX];
int top = -1;

// Function Prototypes
void push(int value);
void pop();
void display();

int main() {
    int choice, value;

    printf("\n:: Stack Operations using Array ::\n");
    while (1) {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// --- Function Definitions ---

// Function to Push (Add element)
void push(int value) {
    // Check for Stack Overflow
    if (top == MAX - 1) {
        printf("Error: Stack Overflow! Cannot push %d.\n", value);
    } else {
        top++;              // 1. Increment top pointer
        stack[top] = value; // 2. Add value to the stack
        printf("%d pushed onto the stack.\n", value);
    }
}

// Function to Pop (Remove element)
void pop() {
    // Check for Stack Underflow
    if (top == -1) {
        printf("Error: Stack Underflow! Stack is empty.\n");
    } else {
        printf("Popped element: %d\n", stack[top]);
        top--; // Decrement top pointer
    }
}

// Function to Display stack elements
void display() {
    if (top == -1) {
        printf("Stack is Empty.\n");
    } else {
        printf("Stack elements: \n");
        // Print from Top down to 0 to visualize LIFO
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}