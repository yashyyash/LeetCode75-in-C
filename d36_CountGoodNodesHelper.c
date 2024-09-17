#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Helper function to count good nodes
int countGoodNodesHelper(struct TreeNode* node, int maxSoFar) {
    if (node == NULL) {
        return 0;
    }

    // Check if the current node is good
    int good = 0;
    if (node->val >= maxSoFar) {
        good = 1;
    }

    // Update maxSoFar with the maximum value encountered in the path
    maxSoFar = (node->val > maxSoFar) ? node->val : maxSoFar;

    // Recursively count good nodes in left and right subtrees
    return good + countGoodNodesHelper(node->left, maxSoFar) + countGoodNodesHelper(node->right, maxSoFar);
}

// Function to count good nodes in the binary tree
int countGoodNodes(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    // Start recursion with root node and its value as the initial maxSoFar
    return countGoodNodesHelper(root, root->val);
}

// Function to create a new binary tree node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    // Example 1: Create the tree [3,1,4,3,null,1,5]
    struct TreeNode* root = createNode(3);
    root->left = createNode(1);
    root->right = createNode(4);
    root->left->left = createNode(3);
    root->right->left = createNode(1);
    root->right->right = createNode(5);

    // Count good nodes
    int goodNodesCount = countGoodNodes(root);
    printf("Number of good nodes: %d\n", goodNodesCount);

    return 0;
}
