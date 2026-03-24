#include <stddef.h>

/*
Question 3: Sum Root to Leaf Numbers

You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path represents a number.
For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.

Return the total sum of all root-to-leaf numbers.

A leaf node is a node with no children.

Examples:

Example 1:
Input:
        1
       / \
      2   3
Output: 25
Explanation:
The root-to-leaf path 1->2 represents 12.
The root-to-leaf path 1->3 represents 13.
12 + 13 = 25.

Example 2:
Input:
          4
         / \
        9   0
       / \
      5   1
Output: 1026
Explanation:
The numbers are 495, 491, and 40.
495 + 491 + 40 = 1026.

Function to complete:
    int sumNumbers(struct TreeNode* root);

Note:
- Each node stores a digit from 0 to 9.
- If the tree is empty, return 0.
- Build the current number as you move from root to leaf.
*/

/*
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


// helper function to recursively build numbers
int dfs(struct TreeNode* node, int current) {
    // If node is NULL, no contribution to sum
    if (node == NULL) {
        return 0;
    }

    // updating the current number:
    // shifting digits left (multiply by 10) and adding current node value
    current = current * 10 + node->val;

    // if it's a leaf node then return the formed number
    if (node->left == NULL && node->right == NULL) {
        return current;
    }

    // recurrsion for left and right subtrees and sum their results
    return dfs(node->left, current) + dfs(node->right, current);
}


int sumNumbers(struct TreeNode* root) {
      // TODO: implement


      // if tree is empty then sum is 0
    if (root == NULL) {
        return 0;
    }

    // start DFS with initial value 0
    return dfs(root, 0);

}