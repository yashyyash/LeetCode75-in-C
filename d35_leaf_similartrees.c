#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to create a new tree node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to collect leaf nodes
void collectLeaves(struct TreeNode* root, int* leaves, int* index) {
    if (!root) return;
    if (!root->left && !root->right) {
        leaves[(*index)++] = root->val;
        return;
    }
    collectLeaves(root->left, leaves, index);
    collectLeaves(root->right, leaves, index);
}

// Function to compare leaf-similarity of two trees
bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    int leaves1[200], leaves2[200];
    int index1 = 0, index2 = 0;
    
    collectLeaves(root1, leaves1, &index1);
    collectLeaves(root2, leaves2, &index2);
    
    if (index1 != index2) return false;
    
    for (int i = 0; i < index1; i++) {
        if (leaves1[i] != leaves2[i]) return false;
    }
    
    return true;
}

int main() {
    // Create first tree: [3,5,1,6,2,9,8,null,null,7,4]
    struct TreeNode* root1 = createNode(3);
    root1->left = createNode(5);
    root1->right = createNode(1);
    root1->left->left = createNode(6);
    root1->left->right = createNode(2);
    root1->right->left = createNode(9);
    root1->right->right = createNode(8);
    root1->left->right->left = createNode(7);
    root1->left->right->right = createNode(4);

    // Create second tree: [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
    struct TreeNode* root2 = createNode(3);
    root2->left = createNode(5);
    root2->right = createNode(1);
    root2->left->left = createNode(6);
    root2->left->right = createNode(7);
    root2->right->left = createNode(4);
    root2->right->right = createNode(2);
    root2->right->right->left = createNode(9);
    root2->right->right->right = createNode(8);

    // Check if leaf-similar
    bool result = leafSimilar(root1, root2);

    if (result) {
        printf("The trees are leaf-similar.\n");
    } else {
        printf("The trees are not leaf-similar.\n");
    }

    // Free the memory for the trees (not implemented for simplicity)

    return 0;
}
