#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void DisplayLL() {
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void DisplayAddressLL() {
    struct node *ptr;
    ptr = head;
    while (ptr != NULL) {
        printf("Node val=%d,add=%p\t", ptr->data, (void *)ptr);
        printf("Next node add=%p\n", (void *)ptr->next);
        ptr = ptr->next;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    srand(time(NULL));
    
    struct node *current = NULL;
    for (int i = 0; i < n; i++) {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = (rand() % 100) + 1; 
        newNode->next = NULL;
        
        if (head == NULL) {
            head = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }
    
    DisplayLL();
    DisplayAddressLL();
    
    return 0;
}