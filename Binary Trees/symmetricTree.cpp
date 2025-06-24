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

//LEETCODE: 101

/*3 cases to remember in mind:
1. if donhi root che values NULL ahet.
2. if kontya eka root chi value (i.e either left root kevha right root chi values) NULL ahet.
3. if donhi root che values NOT NULL ahet.
*/


/*Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Example 1:
Input: root = [1,2,2,3,4,4,3]
Output: true

Example 2:
Input: root = [1,2,2,null,3,null,3]
Output: false*/

class Solution {
public:
    bool check(TreeNode* L, TreeNode* R){

        // cond 1: If both are NULL
        if(L == NULL && R == NULL) return true;

        // cond 2: If one of them is NULL and other is NOT NULL
        if(L == NULL || R == NULL) return false;

        // cond 3; If both are not NULL
        if(L->val == R->val && check(L->right, R->left) && check(L->left, R->right)){
            return true;
        }
        return false;
    }

    bool isSymmetric(TreeNode* root) {
        return check(root->left,root->right);
    }
};

