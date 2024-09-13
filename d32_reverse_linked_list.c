#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to reverse the linked list
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;  // base case: return if list is empty or has 1 node
    }

    struct ListNode* newHead = reverseList(head->next);
    head->next->next = head;  // reverse the next node's pointer
    head->next = NULL;        // set the current node's next to NULL

    return newHead;  // return the new head node
}

int main() {
    // Assume param_1 is initialized and points to the head of a linked list
    struct ListNode* param_1 = NULL; // Example initialization
    // Call reverseList
    struct ListNode* ret = reverseList(param_1);

    // Printing or further processing ret as needed
    return 0;
}
