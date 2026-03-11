/*
 * Assignment 2 / Question 1 / student.c
 * ------------------------------------------------------------
 * Search in a Binary Search Tree (BST)
 *
 * Implement:
 *   struct TreeNode* bstSearch(struct TreeNode* root, int target);
 *
 * Rules:
 * - Return a pointer to the node with value == target, else NULL.
 * - Do NOT allocate new nodes.
 * - Do NOT modify the tree.
 * - Do NOT print anything.
 *
 * Build/Run (from Assignment2 folder):
 *   make run1
 */

#include <stddef.h>  // NULL

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* bstSearch(struct TreeNode* root, int target) {
    // TODO: implement
    // Hint: Use the BST property to decide whether to go left or right.
    // Traversing the tree untill we find the value or reach (NULL)

    while(root != NULL)
    {
        //checking if the current node contains the target value 
        if (root->val == target) 
        {
            return root; // returning pointer to this node
        }
        // If the target is smaller than current node value then searching in the left subtree
        else if (target < root->val) 
        {
            root = root->left;
        }
        // If target is larger than current node value then searching in the right subtree
        else 
        {
            root = root->right;
        }
    }

    return NULL;
}
