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

/*NODE: Here there are cases which are to be taken care of: if the node which is to be removed is a->
1.LEAF NODE: simply remove it from BST
2. Node with one child: If the node has one child, we can bypass the node by connecting its parent directly to its child.
3. Node with two children: If the node has two children, we need to find the node's in-order 
successor (the smallest node in its right subtree) or in-order predecessor (the largest node in its left subtree) 
to replace the node's value and then delete that successor or predecessor node.
*/

/*Given a root node reference of a BST and a key, 
delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.
Basically, the deletion can be divided into two stages:
Search for a node to remove.
If the node is found, delete the node.

Example 1:
Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

Example 2:
Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.

Example 3:
Input: root = [], key = 0
Output: []*/

class Solution {
public:
    TreeNode* helper(TreeNode* root) {
        if (root->left == NULL)
            return root->right;
        else if (root->right == NULL)
            return root->left;

        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRightNode(root->left);
        lastRight->right = rightChild;
        return root->left;
    }

    TreeNode* findLastRightNode(TreeNode* root) {
        while (root->right != NULL)
            root = root->right;
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return NULL;

        if (root->val == key)
            return helper(root);
        TreeNode* dummy = root;

        while (root != NULL) {
            if (root->val > key) {
                if (root->left != NULL && root->left->val == key) {
                    root->left = helper(root->left);
                    break;
                } else
                    root = root->left;
            } else {
                if (root->right != NULL && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                } else
                    root = root->right;
            }
        }
        return dummy;
    }
};