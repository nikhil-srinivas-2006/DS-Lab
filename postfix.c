#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <string.h>

#define MAX 100
char stack[MAX];
int top = -1;


void push(char item) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = item;
    }
}

char pop() {
    if (top == -1) {
        return -1; 
    } else {
        return stack[top--];
    }
}

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


int main() {
    char infix[MAX], postfix[MAX];
    int i = 0, j = 0;
    char item, x;

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    while (infix[i] != '\0') {
        item = infix[i];

        if (isalnum(item)) {
            postfix[j++] = item;
        }
        
        else if (item == '(') {
            push(item);
        }
        else if (item == ')') {
            while ((x = pop()) != '(') {
                postfix[j++] = x;
            }
        }
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(item)) {
                postfix[j++] = pop();
            }
            push(item); 
        }

        i++;
    }

    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
