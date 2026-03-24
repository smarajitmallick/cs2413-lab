#include <stdbool.h>
#include <stddef.h>

/*
Question 2: Symmetric Tree

Given the root of a binary tree, check whether it is symmetric
around its center.

A tree is symmetric if the left subtree is a mirror reflection
of the right subtree.

Examples:

Example 1:
Input:
        1
       / \
      2   2
     / \ / \
    3  4 4  3
Output: true

Example 2:
Input:
        1
       / \
      2   2
       \   \
       3    3
Output: false

Function to complete:
    bool isSymmetric(struct TreeNode* root);

Note:
- An empty tree is considered symmetric.
- You should compare the left subtree and right subtree
  as mirror images.
*/

/*
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// helper function to check if two subtrees are mirror images

bool isMirror(struct TreeNode* left, struct TreeNode* right) {
    
  // to check if both nodes are NULL, they are symmetric
    if (left == NULL && right == NULL) {
        return true;
    }

// if only one is NULL and not symmetric

    if (left == NULL || right == NULL) {
        return false;
    }

// If values are different and not symmetric

    if (left->val != right->val) {
        return false;
    }

    // Checking 
    // 1. left subtree of 'left' with right subtree of 'right'
    // 2. right subtree of 'left' with left subtree of 'right'

    return isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root) {
  // TODO: implement
// an empty tree is symmetric
  if (root == NULL) {
        return true;
    }
// checking if left and right subtrees are mirrors
    return isMirror(root->left, root->right);

}