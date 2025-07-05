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

//LEETCODE: 653

/*Given the root of a binary search tree and an integer k, 
return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

Example 1:
Input: root = [5,3,6,2,4,null,7], k = 9
Output: true

Example 2:
Input: root = [5,3,6,2,4,null,7], k = 28
Output: false*/

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> nodes;
        deque<TreeNode*> dq;

        dq.push_back(root);

        while (!dq.empty()) {
            TreeNode* curr = dq.front();
            dq.pop_front();
            nodes.insert(curr->val);

            if (curr->left) dq.push_back(curr->left);
            if (curr->right) dq.push_back(curr->right);
        }

        for (auto val : nodes) {
            int complement = k - val;
            if (nodes.find(complement) != nodes.end()) { //check if the complement we are searching is not the element itself.
                if (complement != val)
                    return true;
            }
        }

        return false;
    }
};
