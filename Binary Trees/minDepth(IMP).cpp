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


//1] USING BFS
class Solution {
    public:
        int minDepth(TreeNode* root) {
            if(root == NULL) return 0;
    
            int depth = 1;
            deque<TreeNode*> dq;
            dq.push_back(root);
    
            while(!dq.empty()){
                int n = dq.size();
    
                for(int i=0;i<n;i++){
                    TreeNode* curr = dq.front();
                    dq.pop_front();
    
                    if(curr->left == NULL && curr->right == NULL) return depth;
                    if(curr->left != NULL) dq.push_back(curr->left);
                    if(curr->right != NULL) dq.push_back(curr->right);
                }
                depth++; //ithe apan temp array chya evji ek 
            }
            return -1;
        }
    };


//2] USING DFS