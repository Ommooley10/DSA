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


/*Given the root of a binary tree, return all root-to-leaf paths in any order.
A leaf is a node with no children.

Example 1:
Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]

Example 2:
Input: root = [1]
Output: ["1"]*/

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

    void getPath(TreeNode* root, string path, vector<string>& ans){
        if(root->left == NULL && root->right == NULL){
            ans.push_back(path);
        }

        if(root->left != NULL){
            getPath(root->left, path + "->" + to_string(root->left->val),ans);
        }

        if(root->right != NULL){
            getPath(root->right, path + "->" + to_string(root->right->val),ans);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path = to_string(root->val);

        getPath(root, path, ans);
        return ans;
    }
};