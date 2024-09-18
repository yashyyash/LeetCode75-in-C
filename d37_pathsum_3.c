#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to count the number of paths with the given sum starting from a particular node.
int countPaths(struct TreeNode* root, int sum) {
    if (root == NULL) {
        return 0;
    }
    
    int count = 0;
    if (root->val == sum) {
        count++;
    }
    
    count += countPaths(root->left, sum - root->val);
    count += countPaths(root->right, sum - root->val);
    
    return count;
}

// Main function to calculate the total number of paths in the tree that sum to the target.
int pathSum(struct TreeNode* root, int targetSum) {
    if (root == NULL) {
        return 0;
    }
    
    int count = countPaths(root, targetSum);
    count += pathSum(root->left, targetSum);
    count += pathSum(root->right, targetSum);
    
    return count;
}

// Helper function to create a new TreeNode.
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    // Constructing the tree from the example
    struct TreeNode* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(-3);
    root->left->left = newNode(3);
    root->left->right = newNode(2);
    root->right->right = newNode(11);
    root->left->left->left = newNode(3);
    root->left->left->right = newNode(-2);
    root->left->right->right = newNode(1);

    int targetSum = 8;
    int result = pathSum(root, targetSum);
    printf("Number of paths that sum to %d: %d\n", targetSum, result);

    // Free allocated memory (good practice to avoid memory leaks)
    free(root->left->left->left);
    free(root->left->left->right);
    free(root->left->right->right);
    free(root->left->left);
    free(root->left->right);
    free(root->right->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
