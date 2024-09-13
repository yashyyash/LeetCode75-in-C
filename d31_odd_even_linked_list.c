#include <stdio.h>
#include <stdlib.h>

// Assuming ListNode struct is already defined as below
struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to rearrange nodes in odd-even fashion
struct ListNode* oddEvenList(struct ListNode* head) {
    // Edge case: if the list is empty or has only one node
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Initialize pointers
    struct ListNode* odd = head;            // Start with the first node
    struct ListNode* even = head->next;     // Start with the second node
    struct ListNode* evenHead = even;       // Keep track of the head of the even list

    // Traverse the list and rearrange the nodes
    while (even != NULL && even->next != NULL) {
        odd->next = even->next; // Link the current odd node to the next odd node
        odd = odd->next;        // Move the odd pointer
        even->next = odd->next; // Link the current even node to the next even node
        even = even->next;      // Move the even pointer
    }

    // Link the end of the odd list to the head of the even list
    odd->next = evenHead;

    return head;
}

// Function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original list: \n");
    printList(head);

    // Call oddEvenList function
    head = oddEvenList(head);

    printf("List after rearranging odd and even nodes: \n");
    printList(head);

    // Free the remaining nodes
    while (head != NULL) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
