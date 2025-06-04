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

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return check(root) != -1;  // return true if balanced
    }

private:
    int check(TreeNode* root) {
        if (root == nullptr) return 0;

        int LeftHeight = check(root->left);
        if (LeftHeight == -1) return -1;

        int RightHeight = check(root->right);
        if (RightHeight == -1) return -1;

        if (abs(LeftHeight - RightHeight) > 1) return -1;

        return 1 + max(LeftHeight, RightHeight);  // return height if balanced
    }
};
