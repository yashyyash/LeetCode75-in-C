#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to create a new tree node.
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

// Function to get the right side view of the binary tree
int* rightSideView(struct TreeNode* root, int* returnSize) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int* result = (int*)malloc(100 * sizeof(int));  // Max size based on constraints
    *returnSize = 0;

    Queue* queue = createQueue(100);
    enqueue(queue, root);

    while (!isEmpty(queue)) {
        int levelSize = queue->rear - queue->front;  // Number of nodes at current level

        for (int i = 0; i < levelSize; ++i) {
            struct TreeNode* node = dequeue(queue);
            
            // Save the rightmost node of the current level
            if (i == levelSize - 1) {
                result[(*returnSize)++] = node->val;
            }

            if (node->left) {
                enqueue(queue, node->left);
            }
            if (node->right) {
                enqueue(queue, node->right);
            }
        }
    }

    free(queue->data);
    free(queue);
    
    return result;
}

// Main function to test the solution
int main() {
    // Example tree: [1, 2, 3, NULL, 5, NULL, 4]
    //        1
    //      /   \
    //     2     3
    //      \     \
    //       5     4

    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(5);
    root->right->right = newNode(4);

    int returnSize;
    int* result = rightSideView(root, &returnSize);

    printf("Right side view: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);

    return 0;
}
