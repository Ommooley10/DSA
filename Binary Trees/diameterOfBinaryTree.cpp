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
    int maxDiameter = 0;

    int height(TreeNode* root) {
        if (!root) return 0;

        int lh = height(root->left);
        int rh = height(root->right);

        // Update the diameter at every node
        maxDiameter = max(maxDiameter, lh + rh);

        // Return height of current node
        return 1 + max(lh, rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);  // Trigger post-order traversal
        return maxDiameter;
    }
};