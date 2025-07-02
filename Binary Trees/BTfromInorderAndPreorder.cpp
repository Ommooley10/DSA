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

/*LEETCODE: 105*/

/*NOTE:
    1. The first element of preorder vector is always the root.
    2. Take the element from preorder vector, make it the root and find that element in the inorder vector.
    3. The set of elements on the left and the right side of the root element in the inorder array will be the 
    left and right subtree of that root element.
    4. Recursively do the same with the left and right subtree as now theey have their own root nodes and 
    further tree is to be generated.
*/

/*Given two integer arrays preorder and inorder where preorder is the preorder traversal 
of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

Example 1:
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: preorder = [-1], inorder = [-1]
Output: [-1]*/


class Solution {
public:
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, int& idx){
        if(start > end) return NULL;

        int rootVal = preorder[idx];
        int rootPos;
        for(int i=0;i<=end;i++){
            if(inorder[i] == rootVal) rootPos = i;
        }
        idx++;

        TreeNode* root = new TreeNode(rootVal);
        root->left = solve(preorder, inorder, start, rootPos-1, idx);
        root->right = solve(preorder, inorder, rootPos+1, end, idx);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int start = 0;
        int end = inorder.size()-1;
        int idx = 0;
        return solve(preorder, inorder, start, end, idx);
    }
};