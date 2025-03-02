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

//1] PREORDER TRAVERSAL
class Solution {
    public:
        vector<int> ans;
    
        void preorder(TreeNode* root){
            if(root == NULL) return;
    
            ans.push_back(root->val);
            preorder(root->left);
            preorder(root->right);
    
        }
        vector<int> preorderTraversal(TreeNode* root) {
            preorder(root);
            return ans;     
        }
    };

//2] INORDER TRAVERSAL
class Solution {
    public:
    
        vector<int>ans;
    
        void inorder(TreeNode* root){
            if(root == NULL) return;
    
            inorder(root->left);
            ans.push_back(root->val);
            inorder(root->right);
        }
        vector<int> inorderTraversal(TreeNode* root) {
            inorder(root);
            return ans;
        }
    };

//3] POSTORDER TRAVERSAL
class Solution {
    public:
    
        vector<int>ans;
    
        void postorder(TreeNode* root){
            if(root == NULL) return;
    
            postorder(root->left);
            postorder(root->right);
            ans.push_back(root->val);
        }
        vector<int> postorderTraversal(TreeNode* root) {
            postorder(root);
            return ans;
        }
    };