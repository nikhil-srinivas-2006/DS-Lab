#include <stdio.h>
#include <stdlib.h>
#define max_size 5

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* createNode(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

int get_size(Node** head) {
    int count = 0;
    Node* temp = *head;
    while(temp != NULL) {
        temp = temp->next;
        count++;
    }
    return count;
}

void display(Node** head) {
    Node* temp = *head;
    while(temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void peek(Node** head) {
    printf("%d\n", (*head)->data);
}


void push(Node** head, int data) {
    if(get_size(&(*head)) == max_size) {
        printf("Stack Overflow\n");
        return;
    }
    Node* new_node = createNode(data);
    if(*head == NULL) {
        *head = new_node;
        return;
    }
    new_node->next = *head;
    *head = new_node;
}

void pop(Node** head) {
    if(*head == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

int main() {
    Node* head = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    display(&head);
    push(&head, 40);
    push(&head, 50);
    push(&head, 60);
    display(&head);
    peek(&head);
    pop(&head);
    display(&head);
}
