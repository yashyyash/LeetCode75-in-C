struct ListNode* deleteMiddle(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        // If the list has 0 or 1 node, return NULL
        free(head);
        return NULL;
    }

    // Use two pointers: slow and fast
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    struct ListNode *prev = NULL;  // To track the node before slow
    
    // Move fast pointer 2 steps and slow pointer 1 step at a time
    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // Delete the middle node
    prev->next = slow->next;
    free(slow);

    return head;
}
