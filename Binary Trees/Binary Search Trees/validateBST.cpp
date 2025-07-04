#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//LEETCODE: 98

/*Given the root of a binary tree, determine if it is a valid binary search tree (BST).
A valid BST is defined as follows:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 
Example 1:
Input: root = [2,1,3]
Output: true

Example 2:
Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.*/



/*                                             !!! WRONG SOLUTION !!!

This solution is wrong as it only checks the SMALLER PIC i.e the corresponding left and right value of the current node and if the
condition a satisfied it returns true but it ignores the BIGGER PICTURE which is to check the node val with respect to the root NODE value.
*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL)
            return true;
        
        if(root->left == NULL && root->right == NULL) return true;

        if (root->left != NULL && root->right != NULL) {
            if ((root->left->val >= root->val) || (root->right->val <= root->val))
                return false;
        }else if(root->right == NULL){
            return (root->left->val < root->val);
        }else return (root->right->val > root->val);

        return (isValidBST(root->left) && isValidBST(root->right));
    }
};


/*                                      !!! CORRECT SOLUTION: !!!

This is a correct solution as it checks the current node value with the minVal and maxVal that the current node can have 
and this minVal and maxVal (initially set to INT_MIN and INT_MAX) is decided with a simple intuition:

1.The left part/subtree of the curr node should contain value less than it and the right part/subtree contains value bigger than it.
2.the value of the current node should be greater than minVal and less than maxVal
3.[minVal, maxVal] in case of LEFT child of curr node => [minVal, node->val]
[minVal, maxVal] in case of RIGHT child of curr node => [node->val, maxVal]
*/

class Solution {
public:
    bool checkBST(TreeNode* root, long minVal, long maxVal) {
        if (root == NULL)
            return true;

        if (root->val <= minVal || root->val >= maxVal) return false;

        return (checkBST(root->left, minVal, root->val) &&
                checkBST(root->right, root->val, maxVal));
    }

    bool isValidBST(TreeNode* root) { return checkBST(root, LONG_MIN, LONG_MAX); }
};