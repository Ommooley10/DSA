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

//LEETCODE: 230

/*Given the root of a binary search tree, and an integer k, 
return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

Example 1:
Input: root = [3,1,4,null,2], k = 1
Output: 1

Example 2:
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3*/

//SOLN 1: USING BREADTH FIRST SEARCH:
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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> nodes;
        deque<TreeNode*> dq;

        dq.push_back(root);

        while (!dq.empty()) {
            TreeNode* curr = dq.front();
            dq.pop_front();
            nodes.push_back(curr->val);

            if (curr->left) dq.push_back(curr->left);
            if (curr->right) dq.push_back(curr->right);
        }
        sort(nodes.begin(),nodes.end());
        return nodes[k-1];
    }
};


//SOLN 2: USING INORDER TRAVERSAL i.e DEPTH FIRST SEARCH  (REMEMBER THAT INORDER TRAVERSAL OF A BINARY SEARCH TREE IS ALWAYS SORTED)
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& nodes){
        if(root == NULL) return;

        inorder(root->left, nodes);
        nodes.push_back(root->val);
        inorder(root->right, nodes);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> nodes;

        inorder(root, nodes);
        return nodes[k-1];   
    }
};
