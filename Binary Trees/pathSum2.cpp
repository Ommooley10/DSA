#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// QUESTIONS IS SAME AS "rootToLeafNodePath.cpp" just in case of vectors you need to backrack but in string you need not. 

/*Given the root of a binary tree and an integer targetSum, 
return all root-to-leaf paths where the sum of the node values in the path equals targetSum. 
Each path should be returned as a list of the node values, not node references.
A root-to-leaf path is a path starting from the root and ending at any leaf node. 
A leaf is a node with no children.

Example 1:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22

Example 2:
Input: root = [1,2,3], targetSum = 5
Output: []

Example 3:
Input: root = [1,2], targetSum = 0
Output: []*/
 

class Solution {
public:
    void getPath(TreeNode* root, vector<vector<int>>& ans, vector<int>& path, int sum, int targetSum){

        if(root->left == NULL && root->right == NULL){
            if(sum == targetSum){
                ans.push_back(path);
            }
        }

        if(root->left != NULL){
            sum += root->left->val;
            path.push_back(root->left->val);
            getPath(root->left, ans, path, sum, targetSum);

            path.pop_back(); //backtrack if the sum != targetSum
            sum -= root->left->val;
        }

        if(root->right != NULL){
            sum += root->right->val;
            path.push_back(root->right->val);
            getPath(root->right, ans, path, sum, targetSum);

            path.pop_back();  //backtrack if the sum != targetSum
            sum -= root->right->val;
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        vector<int> path;
        path.push_back(root->val);
        int sum =root->val;
        getPath(root,ans, path, sum, targetSum);

        return ans;
    }
};