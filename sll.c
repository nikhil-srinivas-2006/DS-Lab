#include <stdio.h>
#include <stdlib.h>

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

void insert_beg(Node** head, int data) {
    Node* new_node = createNode(data);
    if(*head == NULL) {
        *head = new_node;
        return;
    }
    new_node->next = *head;
    *head = new_node;
}

void insert_end(Node** head, int data) {
    Node* new_node = createNode(data);
    if(*head == NULL) {
        *head = new_node;
        return;
    }
    Node* temp = *head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void insert_mid(int data, int pos, Node** head) {
    Node* new_node = createNode(data);
    if(*head == NULL) {
        *head = new_node;
        return;
    }
    Node* temp = *head;
    int i;
    for(i = 1; temp != NULL; i++) {
        if(i == pos) {
            new_node->next = temp->next;
            temp->next = new_node;
            return;
        }
        temp = temp->next;
    }
    printf("Position out of bounds\n");
}

void display(Node** head) {
    Node* temp = *head;
    while(temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    insert_beg(&head, 10);
    insert_beg(&head, 20);
    display(&head);
    insert_end(&head, 30);
    insert_end(&head, 40);
    display(&head);
    insert_mid(50, 2, &head);
    display(&head);
}
