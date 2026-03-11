/*
 * Assignment 2 / Question 2 / student.c
 * ------------------------------------------------------------
 * Check if a BST is an AVL tree
 *
 * Implement:
 *   bool isAVL(struct TreeNode* root);
 *
 * AVL (for this assignment) means:
 * 1) strict BST property (no duplicates)
 * 2) height-balanced: abs(height(left) - height(right)) <= 1 at every node
 *
 * Rules:
 * - Do NOT allocate new nodes.
 * - Do NOT modify the tree.
 * - Do NOT print anything.
 *
 * Build/Run (from Assignment2 folder):
 *   make run2
 */

#include <stdbool.h>
#include <stddef.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


int checkAVL(struct TreeNode* node, int *prev, bool *first) {

    if (node == NULL)
        return 0;

    // checking left subtree
    int leftHeight = checkAVL(node->left, prev, first);
    if (leftHeight == -1)
        return -1;

    // BST property checking (inorder traversal must be strictly increasing)
    if (!(*first) && node->val <= *prev)
        return -1;

    *first = false;
    *prev = node->val;

    // checking right subtree
    int rightHeight = checkAVL(node->right, prev, first);
    if (rightHeight == -1)
        return -1;

    // AVL balance condition checking
    if (leftHeight - rightHeight > 1 || rightHeight - leftHeight > 1)
        return -1;

    // returning subtree height
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}



bool isAVL(struct TreeNode* root) 
{
    int prev = 0;
    bool first = true;

    return checkAVL(root, &prev, &first) != -1;

}    
    

/*
Helper function that:
1) Checks BST property using min/max bounds
2) Computes subtree height
3) Returns -1 if subtree is invalid (not BST or not balanced)
*/




