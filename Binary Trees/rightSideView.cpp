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

/*Given the root of a binary tree, imagine yourself standing on the right side of it, 
return the values of the nodes you can see ordered from top to bottom.

Example 1:
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]

Example 2:
Input: root = [1,2,3,4,null,null,null,5]
Output: [1,3,4,5]

Example 3:
Input: root = [1,null,3]
Output: [1,3]

Example 4:
Input: root = []
Output: []*/

//SOLUTION 1: USING LEVEL ORDER TRAVERSAL
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;

        deque<TreeNode*> dq;
        dq.push_back(root);

        while(!dq.empty()){
            TreeNode* curr = NULL;
            int n = dq.size();

            while(n--){
                curr = dq.front();
                dq.pop_front();

                if(curr->left != NULL) dq.push_back(curr->left);
                if(curr->right != NULL) dq.push_back(curr->right);
            }
            ans.push_back(curr->val);
        }
        return ans;
    }
};


//Using DFS (Preorder traversal): each level requires one value to be entered in the ans vector. for eg if there are total 3 levels in a binary tree then the size of ans vector i.e ans.size() = 3;
class Solution {
public:
    void preorder(TreeNode* root, int level, vector<int>& ans){
        if(root == NULL) return;

        if(ans.size() < level){
            ans.push_back(root->val);
        }

        preorder(root->right, level+1, ans);
        preorder(root->left, level+1, ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;

        preorder(root,1,ans);

        return ans;
    }
};