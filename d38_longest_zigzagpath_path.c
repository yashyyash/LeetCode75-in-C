#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void zigzagDFS(struct TreeNode* node, int direction, int length, int* maxLength) {
    if (!node) return;

    // Update the maximum length if needed
    if (length > *maxLength) {
        *maxLength = length;
    }

    // If current direction is left (0), go right next (1), and vice versa
    if (direction == 0) {
        // Move left to right
        zigzagDFS(node->left, 1, length + 1, maxLength);
        zigzagDFS(node->right, 0, 1, maxLength); // Start a new path
    } else {
        // Move right to left
        zigzagDFS(node->right, 0, length + 1, maxLength);
        zigzagDFS(node->left, 1, 1, maxLength); // Start a new path
    }
}

int longestZigZag(struct TreeNode* root) {
    int maxLength = 0;

    // Start ZigZag from root as left (0) and right (1)
    zigzagDFS(root, 0, 0, &maxLength);
    zigzagDFS(root, 1, 0, &maxLength);

    return maxLength;
}

// Function to create a new TreeNode
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int main() {
    // Create a simple binary tree for testing
    struct TreeNode* root = createNode(1);
    root->right = createNode(1);
    root->right->left = createNode(1);
    root->right->right = createNode(1);
    root->right->right->left = createNode(1);
    root->right->right->left->left = createNode(1);

    int result = longestZigZag(root);
    printf("Longest ZigZag Path Length: %d\n", result);

    // Free memory (not shown here)
    return 0;
}
