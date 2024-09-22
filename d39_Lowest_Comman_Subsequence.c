#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to find the lowest common ancestor (LCA).
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL || root == p || root == q) {
        return root;
    }

    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left != NULL && right != NULL) {
        return root;
    }

    return left != NULL ? left : right;
}

// Helper function to create a new tree node.
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {
    // Example tree:
    //        3
    //      /   \
    //     5     1
    //    / \   / \
    //   6   2 0   8
    //      / \
    //     7   4

    struct TreeNode* root = newNode(3);
    root->left = newNode(5);
    root->right = newNode(1);
    root->left->left = newNode(6);
    root->left->right = newNode(2);
    root->right->left = newNode(0);
    root->right->right = newNode(8);
    root->left->right->left = newNode(7);
    root->left->right->right = newNode(4);

    struct TreeNode* p = root->left;        // Node with value 5
    struct TreeNode* q = root->right;       // Node with value 1

    struct TreeNode* lca = lowestCommonAncestor(root, p, q);
    printf("LCA of %d and %d is %d\n", p->val, q->val, lca->val);  // Output: LCA of 5 and 1 is 3

    return 0;
}
