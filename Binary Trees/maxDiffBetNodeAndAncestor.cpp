#include <bits/stdc++.h>
using namespace std;

//LEETCODE: 1026
/*Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.
A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.

Example 1:
Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.

Example 2:
Input: root = [1,null,2,null,0,3]
Output: 3*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


//1. BRUTE FORCE: But still accepted 
class Solution {
public:
    int maxDiff = INT_MIN;

    void maxDiffRoot(TreeNode* root, TreeNode* child){ //finding the difference of a given root with all its child
        if(root == NULL || child == NULL) return;
        maxDiff = max(maxDiff, abs(root->val - child->val));

        maxDiffRoot(root, child->left);
        maxDiffRoot(root, child->right);
    }

    void allRoots(TreeNode* root){ //exploring all the roots
        if(root == NULL) return;

        maxDiffRoot(root, root->left);
        maxDiffRoot(root, root->right);

        allRoots(root->left);
        allRoots(root->right);

    }

    int maxAncestorDiff(TreeNode* root) {
        allRoots(root);
        return maxDiff;    
    }
};