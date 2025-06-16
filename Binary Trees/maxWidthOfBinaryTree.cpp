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

// LEETCODE: 662   USE LEVEL ORDER TRAVERSAL WHEREVER REQUIRED (usually containing words like width or breadth)
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        deque<pair<TreeNode*, long long>> dq;
        long long maxWidth  = 0;
        if(root == NULL) return maxWidth;
        dq.push_back({root,0});

        while(!dq.empty()){
            long long n = dq.size();
            long long L = dq.front().second;
            long long R = dq.back().second;

            maxWidth = max(maxWidth,R-L+1);

            while(n--){
                TreeNode* curr = dq.front().first;
                long long idx = dq.front().second;
                dq.pop_front();

                if(curr->left != NULL) dq.push_back({curr->left, 2*idx+1});
                if(curr->right != NULL) dq.push_back({curr->right, 2*idx+2});
            }
        }
        return maxWidth;
    }
};
