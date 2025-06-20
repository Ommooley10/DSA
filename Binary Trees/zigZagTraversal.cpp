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
//NOTE: same as level order traversal, just reverse the alternate array in vector<vector<int>> ans;

/*Given the root of a binary tree, return the zigzag level order traversal of its nodes' values.
 (i.e., from left to right, then right to left for the next level and alternate between).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []*/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if (root == NULL)
            return ans;
        deque<TreeNode*> dq;
        dq.push_back(root);

        while (!dq.empty()) {
            int n = dq.size();
            vector<int> temp;
            while (n--) {
                TreeNode* curr = dq.front();
                dq.pop_front();
                temp.push_back(curr->val);

                if(curr->left != NULL) dq.push_back(curr->left);
                if(curr->right != NULL) dq.push_back(curr->right);   
            }
            ans.push_back(temp);
        }

        for(int i=0;i<ans.size();i++){
            if(i%2 != 0){
                reverse(ans[i].begin(),ans[i].end());
            }
        }
        return ans;
    }
};