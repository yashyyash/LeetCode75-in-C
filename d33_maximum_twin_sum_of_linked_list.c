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