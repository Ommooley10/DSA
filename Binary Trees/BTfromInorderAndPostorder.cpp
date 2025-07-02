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
/*LEETCODE: 106*/

/*Given two integer arrays inorder and postorder where inorder is 
the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

Example 1:
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: inorder = [-1], postorder = [-1]
Output: [-1]*/

class Solution {
public:
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd){

        if(inStart > inEnd) return NULL;

        int rootVal = postorder[postEnd];

        int rootPos;
        for(int i=inStart;i<=inEnd;i++){
            if(inorder[i] == rootVal){
                rootPos = i;
                break;
            }
        }

        int leftSize = rootPos - inStart;
        int rightSize = inEnd - rootPos;

        TreeNode* root = new TreeNode(rootVal);
        root->left = solve(inorder, postorder, inStart, rootPos-1, postStart, postStart + leftSize -1);
        root->right = solve(inorder, postorder,rootPos+1, inEnd, postEnd - rightSize, postEnd - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        int n = inorder.size();
        int inStart = 0;
        int inEnd = n-1;

        int postStart = 0;
        int postEnd = n-1;

        return solve(inorder, postorder, inStart, inEnd, postStart, postEnd);
    }
};