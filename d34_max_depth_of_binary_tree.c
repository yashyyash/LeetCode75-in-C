#include <stdio.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to calculate the maximum depth of the binary tree
int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    } else {
        // Recursively find the depth of the left and right subtrees
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        
        // Return the maximum of the two, plus 1 for the current node
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}

int main() {
    // Create a sample binary tree
    struct TreeNode root = {1, NULL, NULL};
    struct TreeNode left = {2, NULL, NULL};
    struct TreeNode right = {3, NULL, NULL};
    struct TreeNode leftLeft = {4, NULL, NULL};
    struct TreeNode leftRight = {5, NULL, NULL};

    root.left = &left;
    root.right = &right;
    left.left = &leftLeft;
    left.right = &leftRight;

    // Calculate and print the maximum depth of the binary tree
    int depth = maxDepth(&root);
    printf("Maximum depth of the binary tree: %d\n", depth);

    return 0;
}