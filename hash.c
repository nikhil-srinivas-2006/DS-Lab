#include <stdio.h>
#include <stdlib.h>

#define MAX 100 


struct Employee {
    int id;        
    char name[20];   
};


struct HashTable {
    struct Employee data;
    int flag; // 0 = Empty, 1 = Occupied
};


struct HashTable ht[MAX];
int m; 
int count = 0;


void initialize() {
    int i;
    for (i = 0; i < MAX; i++) {
        ht[i].flag = 0;
    }
}


void insert(int key, char *name) {
    if (count == m) {
        printf("Error: Hash Table is Full (File F is full).\n");
        return;
    }


    int index = key % m; 


    while (ht[index].flag == 1) {
        printf("Collision detected at address %02d. Probing next...\n", index);
        index = (index + 1) % m; // Wrap around if we reach the end
    }


    ht[index].data.id = key;
    sprintf(ht[index].data.name, "%s", name);
    ht[index].flag = 1;
    count++;

    printf("Record inserted at address (L): %02d\n", index);
}


void display() {
    int i;
    printf("\n--- Hash Table (Memory Addresses L) ---\n");
    printf("Addr\tKey\tName\n");
    printf("----\t----\t----\n");
    
    for (i = 0; i < m; i++) {
        if (ht[i].flag == 1) {
            printf("%02d\t%d\t%s\n", i, ht[i].data.id, ht[i].data.name);
        } else {
            // Optional: Print empty slots or skip them
            // printf("%02d\t----\t----\n", i); 
        }
    }
    printf("\n");
}

int main() {
    int choice, key;
    char name[20];

    printf("Enter the number of memory locations (m): ");
    scanf("%d", &m);

    initialize();

    printf("\n:: Employee Record Hashing System ::\n");
    while (1) {
        printf("1. Insert Record (N)\n");
        printf("2. Display File (F)\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter 4-digit Key (Employee ID): ");
                scanf("%d", &key);
                printf("Enter Employee Name: ");
                scanf("%s", name);
                insert(key, name);
                break;
            case 2:
                display();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}