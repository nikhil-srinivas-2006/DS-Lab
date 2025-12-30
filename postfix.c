#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // For isalnum()
#include <string.h>

#define MAX 100

// Global Stack and Top pointer
char stack[MAX];
int top = -1;

// --- Stack Operations ---

void push(char item) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = item;
    }
}

char pop() {
    if (top == -1) {
        return -1; // Return -1 if empty
    } else {
        return stack[top--];
    }
}

// Function to return precedence of operators
int precedence(char symbol) {
    if (symbol == '^') {
        return 3;
    } else if (symbol == '*' || symbol == '/') {
        return 2;
    } else if (symbol == '+' || symbol == '-') {
        return 1;
    } else {
        return 0;
    }
}

// --- Main Conversion Logic ---

int main() {
    char infix[MAX], postfix[MAX];
    int i = 0, j = 0;
    char item, x;

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    // Loop through the Infix string
    while (infix[i] != '\0') {
        item = infix[i];

        // 1. If operand (A-Z, a-z, 0-9), add directly to Postfix string
        if (isalnum(item)) {
            postfix[j++] = item;
        }
        // 2. If '(', push to stack
        else if (item == '(') {
            push(item);
        }
        // 3. If ')', pop and add to Postfix until '(' is found
        else if (item == ')') {
            while ((x = pop()) != '(') {
                postfix[j++] = x;
            }
        }
        // 4. If operator, manage precedence
        else {
            // While stack top has >= precedence, pop and add to Postfix
            while (top != -1 && precedence(stack[top]) >= precedence(item)) {
                postfix[j++] = pop();
            }
            push(item); // Push the current operator
        }
        i