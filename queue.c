#include <stdio.h>
#include <stdlib.h>

#define SIZE 5 

int queue[SIZE];
int front = -1;
int rear = -1;


void insert(int value);
void delete();
void display();

int main() {
    int choice, value;

    printf("\n:: Queue Implementation using Array ::\n");
    while (1) {
        printf("\n1. Insert (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
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
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}


void insert(int value) {
    // Check for Overflow
    if (rear == SIZE - 1) {
        printf("Error: Queue Overflow! Cannot insert %d.\n", value);
    } else {
        // If queue is initially empty, set front to 0
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = value;
        printf("Inserted %d successfully.\n", value);
    }
}


void delete() {
    if (front == -1 || front > rear) {
        printf("Error: Queue Underflow! Queue is empty.\n");
    } else {
        printf("Deleted element: %d\n", queue[front]);
        front++;

        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }
}


void display() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}