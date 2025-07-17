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
int search_item(int x)
{
    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        if (ptr -> data == x)
        {
            return x;
            ptr = ptr -> next;
        }

        return -1;
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
    printf("%d\n",search_item(65));
    printf("%d\n",search_item(50)); 
    return 0;
}