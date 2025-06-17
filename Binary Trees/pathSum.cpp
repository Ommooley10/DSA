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

/*Given the root of a binary tree and an integer targetSum, 
return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.

Example 1:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.

Example 2:
Input: root = [1,2,3], targetSum = 5
Output: false
Explanation: There are two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.

Example 3:
Input: root = [], targetSum = 0
Output: false
Explanation: Since the tree is empty, there are no root-to-leaf paths.*/

//OPTIMAL:
class Solution {
public:
    bool getSum(TreeNode* root, int sum, int targetSum){
        if(root == NULL) return false;

        sum += root->val;

        if(root->left == NULL && root->right == NULL){
            if(sum == targetSum) return true;
            else return false;
        }

        return(getSum(root->left,sum,targetSum) || getSum(root->right,sum,targetSum));
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;

        return getSum(root, sum, targetSum);
    }
};


//BRUTE FORCE: NOT RECOMMENDED AS THIS REQUIRES A LOT OF SPACE AS WELL AS TIME
/*class Solution {
public:
    void getPath(TreeNode* root, vector<int> path, vector<vector<int>>& ans) {
        if (!root->left && !root->right) {
            ans.push_back(path);
            return;
        }

        if (root->left) {
            vector<int> newPath = path;
            newPath.push_back(root->left->val);
            getPath(root->left, newPath, ans);
        }

        if (root->right) {
            vector<int> newPath = path;
            newPath.push_back(root->right->val);
            getPath(root->right, newPath, ans);
        }
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        vector<vector<int>> ans;
        vector<int> path = {root->val};

        getPath(root, path, ans);

        for (const auto& arr : ans) {
            int sum = accumulate(arr.begin(), arr.end(), 0);
            if (sum == targetSum) return true;
        }

        return false;
    }
};*/
