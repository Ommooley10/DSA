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

//NOTE: Use the property of BST -> inorder traversal of BST is always sorted, so sort the preorder vector to get the inorder.

/*Given an array of integers preorder, 
which represents the preorder traversal of a BST (i.e., binary search tree), 
construct the tree and return its root.
It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, 
any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.

Example 1:
Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

Example 2:
Input: preorder = [1,3]
Output: [1,null,3]*/

//NOTE: The optimal solution can be written using the upper bound 

//BRUTE FORCE:
class Solution {
public:
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& idx,
    int start, int end) {
        if (start > end)
            return NULL;

        int rootVal = preorder[idx];
        int rootPos;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == rootVal) {
                rootPos = i;
                break;
            }
        }
        idx++;

        TreeNode* root = new TreeNode(rootVal);
        root->left = solve(preorder, inorder, idx, start, rootPos - 1);
        root->right = solve(preorder, inorder, idx, rootPos + 1, end);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder;
        for (auto i : preorder) {
            inorder.push_back(i);
        }
        sort(inorder.begin(), inorder.end());

        int idx = 0;
        int start = 0;
        int end = inorder.size() - 1;
        return solve(preorder, inorder, idx, start, end);
    }
};

//OPTIMAL: 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* solve(vector<int>& preorder, int& idx, int bound){
        if(idx >= preorder.size() || preorder[idx] > bound) return NULL;
        TreeNode* root = new TreeNode(preorder[idx]);
        idx++;
        root->left = solve(preorder, idx, root->val);
        root->right = solve(preorder,idx,bound);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        int bound = INT_MAX;

        return solve(preorder, idx, bound);
    }
};
