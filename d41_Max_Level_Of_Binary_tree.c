#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new tree node.
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Queue structure for BFS (level-order traversal)
typedef struct {
    struct TreeNode** data;
    int front, rear, size;
} Queue;

// Initialize the queue
Queue* createQueue(int size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->data = (struct TreeNode**)malloc(size * sizeof(struct TreeNode*));
    queue->front = 0;
    queue->rear = 0;
    queue->size = size;
    return queue;
}

// Enqueue an element to the queue
void enqueue(Queue* queue, struct TreeNode* node) {
    queue->data[queue->rear++] = node;
}

// Dequeue an element from the queue
struct TreeNode* dequeue(Queue* queue) {
    return queue->data[queue->front++];
}

// Check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->front == queue->rear;
}

// Function to find the smallest level with the maximum sum
int maxLevelSum(struct TreeNode* root) {
    if (root == NULL) return 0;

    Queue* queue = createQueue(10000);  // Enough space for BFS for up to 10^4 nodes
    enqueue(queue, root);

    int maxSum = INT_MIN;
    int maxLevel = 0;
    int currentLevel = 0;

    while (!isEmpty(queue)) {
        int levelSize = queue->rear - queue->front;  // Number of nodes at the current level
        int levelSum = 0;
        currentLevel++;

        for (int i = 0; i < levelSize; ++i) {
            struct TreeNode* node = dequeue(queue);
            levelSum += node->val;

            if (node->left) {
                enqueue(queue, node->left);
            }
            if (node->right) {
                enqueue(queue, node->right);
            }
        }

        // Update the maximum sum and corresponding level
        if (levelSum > maxSum) {
            maxSum = levelSum;
            maxLevel = currentLevel;
        }
    }

    free(queue->data);
    free(queue);

    return maxLevel;
}

// Main function for testing
int main() {
    // Example 1 tree: [1, 7, 0, 7, -8]
    //        1
    //      /   \
    //     7     0
    //    / \
    //   7  -8
    struct TreeNode* root = newNode(1);
    root->left = newNode(7);
    root->right = newNode(0);
    root->left->left = newNode(7);
    root->left->right = newNode(-8);

    // Find the smallest level with the maximum sum
    int result = maxLevelSum(root);
    printf("The smallest level with maximum sum is: %d\n", result);  // Output: 2

    return 0;
}
