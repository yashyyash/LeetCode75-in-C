#include <stdio.h>
#include <stdlib.h>

// Definition for a linked list node.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to find the maximum twin sum of a linked list.
int pairSum(struct ListNode* head) {
    // Find the length of the linked list
    struct ListNode* temp = head;
    int length = 0;
    while (temp) {
        length++;
        temp = temp->next;
    }

    // Use an array to store the values of the linked list
    int* values = (int*)malloc(length * sizeof(int));
    temp = head;
    for (int i = 0; i < length; i++) {
        values[i] = temp->val;
        temp = temp->next;
    }

    // Calculate the maximum twin sum
    int maxTwinSum = 0;
    for (int i = 0; i < length / 2; i++) {
        int twinSum = values[i] + values[length - 1 - i];
        if (twinSum > maxTwinSum) {
            maxTwinSum = twinSum;
        }
    }

    // Free the allocated memory
    free(values);

    return maxTwinSum;
}

int main() {
    // Create a sample linked list
    struct ListNode node1 = {1, NULL};
    struct ListNode node2 = {4, NULL};
    struct ListNode node3 = {5, NULL};
    struct ListNode node4 = {2, NULL};

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;

    // Calculate and print the maximum twin sum of the linked list
    int twinSum = pairSum(&node1);
    printf("Maximum twin sum of the linked list: %d\n", twinSum);

    return 0;
}