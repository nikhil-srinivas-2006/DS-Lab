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

void display(Node** front) {
    Node* temp = *front;
    while(temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void enqueue(Node** front, Node** rear,int data) {
    Node* new_node = createNode(data);
    if(*front == NULL) {
        *front = new_node;
        *rear = new_node;
        return;
    }
    Node* temp = *rear;
    temp->next = new_node;
    *rear = new_node;
}


void dequeue(Node** front) {
    if(*front == NULL) {
        printf("Queue Empty");
        return;
    }
    Node* temp = *front;
    *front = (*front)->next;
    free(temp);
}

int main() {
    Node* front = NULL;
    Node* rear = NULL;
    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 20);
    enqueue(&front, &rear, 30);
    display(&front);
    enqueue(&front, &rear, 40);
    enqueue(&front, &rear, 50);
    display(&front);
    dequeue(&front);
    dequeue(&front);
    dequeue(&front);
    display(&front);
}
