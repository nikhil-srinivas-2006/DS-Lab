#include <stdio.h>
#include <stdlib.h>

#define SIZE 5 


int cQueue[SIZE];
int front = -1;
int rear = -1;


void insert(int value);
void delete();
void display();

int main() {
    int choice, value;

    printf("\n:: Circular Queue Operations ::\n");
    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}



void insert(int value) {

    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        printf("Error: Queue Overflow! Cannot insert %d\n", value);
        return;
    }


    if (front == -1) {
        front = 0;
        rear = 0;
    } 
    else {
        rear = (rear + 1) % SIZE;
    }
    
    cQueue[rear] = value;
    printf("Inserted %d\n", value);
}

void delete() {

    if (front == -1) {
        printf("Error: Queue Underflow! Queue is empty.\n");
        return;
    }

    printf("Deleted element: %d\n", cQueue[front]);


    if (front == rear) {
        front = -1;
        rear = -1;
    } 
    else {

        front = (front + 1) % SIZE;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    

    while (i != rear) {
        printf("%d ", cQueue[i]);
        i = (i + 1) % SIZE;
    }

    printf("%d\n", cQueue[rear]);
}