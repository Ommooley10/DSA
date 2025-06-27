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

/*LEETCODE: 1302*/

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        if(root == NULL) return sum;
        vector<vector<int>> result;
        deque<TreeNode*> dq;

        dq.push_back(root);

        while(!dq.empty()){
            vector<int> temp;
            int n=dq.size();

            while(n--){
                TreeNode* curr = dq.front();
                dq.pop_front();
                temp.push_back(curr->val);

                if(curr->left != NULL) dq.push_back(curr->left);
                if(curr->right != NULL) dq.push_back(curr->right);
            }
            result.push_back(temp);
        }
        int n1 = result.size();
        auto arr = result[n1-1];

        sum = accumulate(arr.begin(),arr.end(),0);
        return sum;
    }
};