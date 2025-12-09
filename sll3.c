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

void concat(Node** head1, Node** head2) {
    Node* temp = *head1;
    Node* temp2 = *head2;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    while(temp2 != NULL) {
        temp->next = temp2;
        temp = temp->next;
        temp2 = temp2->next;
    }
    display(&(*head1));
}

void sort(Node** head) {
    Node* temp = *head;
    Node* con = NULL;
    while(temp->next != NULL) {
        con = temp->next;
        while(con != NULL) {
            if(temp->data > con->data) {
                int val = temp->data;
                temp->data = con->data;
                con->data = val;
            }
            con = con->next;
        }
        temp = temp->next;
    }
    display(&(*head));
}

void rev(Node** head) {
    Node* temp = *head;
    Node* prev = NULL;
    Node* next = NULL;
    while(temp != NULL) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    *head = prev;
    display(&(*head));
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
    Node* head2 = NULL;
    insert_end(&head, 30);
    insert_end(&head, 20);
    insert_end(&head, 50);
    display(&head);
    insert_end(&head2, 10);
    insert_end(&head2, 60);
    insert_end(&head2, 40);
    display(&head2);
    concat(&head, &head2);
    sort(&head);
    rev(&head);
}

