#include <stdio.h>
#include <stdlib.h>

// Node Creation
struct Node
{
    int data;
    struct Node *next; // Self refrencing Structure
};

// Function for Linked List Traversal TC: O(n)
void traversal(struct Node *ptr)
{
    while(ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Insertion
// Case:1 Insertion at Begining TC: O(1)
struct Node * insertAtBeg(struct Node *head, int data) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

// Case:2 Insertion at Between/Index TC: O(n)
struct Node * insertAtBet(struct Node *head, int data, int index) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

// Case:3 Insertion at End TC: O(n)
struct Node * insertAtEnd(struct Node *head, int data) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;

    while (p->next!=NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

// Case:4 Insertion After a Node TC: O(1)
struct Node * insertAfterNode(struct Node *head,struct Node *prevNode, int data) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

// ----Deletion----
// Case:1 Deleting from Front TC: O(1)
struct Node * deleteFront(struct Node *head) {
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// Case:2 Deleting from Between/Index TC: O(n)
struct Node * deleteBet(struct Node *head, int index) {
    struct Node *ptr = head;
    struct Node *q = head->next;
    int i = 0;
    while(i<index-1)
    {
        ptr = ptr->next;
        q = q->next;
        i++;
    }
    ptr->next = q->next;
    free(q);
    return head;
}

// Case:3 Deleting from End TC: O(n)
struct Node * deleteEnd(struct Node *head) {
    struct Node *ptr = head;
    struct Node *q = head->next;
    while(q->next != NULL) {
        ptr = ptr->next;
        q = q->next;
    }
    ptr->next = NULL;
    free(q);
    return head;
}

// Case:4 Deleting a Node with Key TC: O(n)
struct Node * deleteByValue(struct Node *head, int value) {
    struct Node *ptr = head;
    struct Node *q = head->next;
    while(q->data != value && q->next != NULL)
    {
        ptr = ptr->next;
        q = q->next;
    }
    if(q->data == value){
        ptr->next = q->next;
        free(q);
    }
    return head;
}

int main()
{
    // Initialising pointer variables
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node)); // Dynamic Memory Allocation
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second Nodes
    head->data = 7;
    head->next = second;

    // Link second and third Nodes
    second->data = 11;
    second->next = third;

    // Link third and fourth Nodes
    third->data = 66;
    third->next = fourth;

    // Terminate the list at the fourth node
    fourth->data = 78;
    fourth->next = NULL;

    //Tarversal TC: O(n)
    printf("Original Nodes:\n");
    traversal(head);
    printf("--------\n");
    
    // ----Insertion----
    // Case:1 Insertion at Begining TC: O(1)
    //head = insertAtBeg(head, 56);
    //traversal(head);

    // Case:2 Insertion at Between/Index TC: O(n)
    //head = insertAtBet(head, 56, 1); //It will not Insert at 0 index.
    //traversal(head);

    // Case:3 Insertion at End TC: O(n)
    //head = insertAtEnd(head, 56);
    //traversal(head);

    // Case:4 Insertion After a Node TC: O(1)
    //head = insertAfterNode(head, second, 45);
    //traversal(head);


    // ----Deletion----
    // Case:1 Deleting from Front TC: O(1)
    //head = deleteFront(head);
    //traversal(head);

    // Case:2 Deleting from Between/Index TC: O(n)
    //head = deleteBet(head, 2);
    //traversal(head);

    // Case:3 Deleting from End TC: O(n)
    //head = deleteEnd(head);
    //traversal(head);

    // Case:4 Deleting a Node with Value TC: O(n-1)
    head = deleteByValue(head, 11);
    traversal(head);

    return 0;
}