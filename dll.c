#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
}Node;

Node* createNode(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

int find(Node* head, int value) {
    Node* temp = head;
    int i=0;
    while(temp != NULL) {
        if(temp->data == value) {
            printf("Node found at position:%d", i+1);
            return;
        }
        i++;
        temp = temp->next;
    }
    printf("Node not found");
}

void display(Node* head){
    Node* temp = head;
    printf("\nDoubly Linked List Structure:\n");
    printf("| %-16s | %-16s | %-5s | %-10s |\n", "Node Addr", "Prev Addr", "Data", "Next Addr");
    while(temp != NULL){
        printf("| %-10p | %-10p | %-5d | %-10p |\n", (void*)temp, (void*)temp->prev, temp->data, (void*)temp->next);
        temp = temp->next;
    }
    printf("\n\n");
}

int main(){
    Node* N1 = createNode(1);
    Node* N2 = createNode(2);
    Node* N3 = createNode(3);
    Node* N4 = createNode(4);
    Node* N5 = createNode(5);

    N1->next = N2;
    N2->prev = N1;
    N2->next = N3;
    N3->prev = N2;
    N3->next = N4;
    N4->prev = N3;
    N4->next = N5;
    N5->prev = N4;

    display(N1);
    find(N1, 4);

    free(N1);
    free(N2);
    free(N3);
    free(N4);
    free(N5);
    return 0;
}
