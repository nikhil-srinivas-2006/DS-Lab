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

void delete_beg(Node** head) {
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void delete_end(Node** head) {
    Node* temp = *head;
    Node* prev = NULL;
    while(temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

void delete_mid(Node** head, int data) {
    Node* temp = *head;
    while(temp->next->data != data && temp->next != NULL) {
        temp = temp->next;
    }
    Node* del = temp->next;
    temp->next = del->next;
    free(del);
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
    insert_end(&head, 10);
    insert_end(&head, 20);
    insert_end(&head, 30);
    insert_end(&head, 40);
    insert_end(&head, 50);
    display(&head);
    delete_beg(&head);
    display(&head);
    delete_end(&head);
    display(&head);
    delete_mid(&head, 30);
    display(&head);
}

