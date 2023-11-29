#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to reverse a doubly linked list
void reverseDoublyLinkedList(struct Node** head) {
    struct Node* current = *head;
    struct Node* next = NULL;
    struct Node* prev = NULL;

    while (current != NULL) {
        next = current->next;  // Save the next node

        // Reverse the links
        current->next = prev;
        current->prev = next;

        // Move to the next nodes
        prev = current;
        current = next;
    }

    // Update the head of the list
    *head = prev;
}

// Function to insert a node at the end of a doubly linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to print a doubly linked list
void printDoublyLinkedList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to free memory allocated for the doubly linked list
void freeDoublyLinkedList(struct Node* head) {
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;

    // Inserting elements at the end of the doubly linked list
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    printf("Original Doubly Linked List: ");
    printDoublyLinkedList(head);

    // Reverse the doubly linked list
    reverseDoublyLinkedList(&head);

    printf("Reversed Doubly Linked List: ");
    printDoublyLinkedList(head);

    // Free the memory allocated for the doubly linked list
    freeDoublyLinkedList(head);

    return 0;
}
