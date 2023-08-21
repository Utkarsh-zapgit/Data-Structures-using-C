#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

// Function of Doubly Linked List Traversal
void traversal(struct Node *ptr) {
    while(ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main() {
    // Initialising pointer variables
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;
    head->prev = NULL;

    second->data = 45;
    second->next = third;
    second->prev = head;

    third->data = 67;
    third->next = fourth;
    third->prev = second;

    fourth->data = 89;
    fourth->next = NULL;
    fourth->prev = third;

    traversal(head);
}