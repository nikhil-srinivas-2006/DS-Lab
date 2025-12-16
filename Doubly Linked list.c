#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* createNode(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void display(Node** head) {
    Node* temp = *head;
    while(temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insert(Node** head, int data) {
    Node* new_node = createNode(data);
    if(*head == NULL) {
        *head = new_node;
        return;
    }
    new_node->next = *head;
    (*head)->prev = new_node;
    *head = new_node;
}

void insert_left(Node** head, int data, int pos) {
    Node* new_node = createNode(data);
    int i;
    Node* temp = *head;
    for(i=1; i < pos && temp->next != NULL; i++) {
        temp = temp->next;
    }
    if(i == pos) {
        new_node->prev = temp->prev;
        temp->prev->next = new_node;
        temp->prev = new_node;
        new_node->next = temp;
        return;
    }
    printf("Index out of bounds");
}

void delete_pos(Node** head, int pos) {
    int i;
    Node* temp = *head;
    for(i=1; i < pos && temp->next != NULL; i++) {
        temp = temp->next;
    }
    if(i == pos) {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
        return;
    }
    printf("Index out of bounds");
}

int main() {
    Node* head = NULL;
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    display(&head);
    insert_left(&head, 50, 2);
    display(&head);
    delete_pos(&head, 3);
    display(&head);
}
