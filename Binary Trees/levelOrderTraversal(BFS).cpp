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


/*1] RETURNING SINGLE ARRAY OF ELEMENTS */  //eg ans={1,2,3,4,5}
class Solution {
    public:
        vector<int> levelOrderUsingSingle(TreeNode* root) {
            vector<int> ans;
            deque<TreeNode*> dq;
    
            dq.push_back(root);
    
            while(!dq.empty()){
                TreeNode* curr = dq.front();
                ans.push_back(curr->val);
                dq.pop_front();
                
                if(curr->left != NULL) dq.push_back(curr->left);
                if(curr->right != NULL) dq.push_back(curr->right);
    
            }
            return ans; // eg ans={1,2,3,4,5}
        }
    };


//2] RETURNING ARRAY OF ARRAY  eg ans={{1},{2,3},{4,5}}
    class Solution {
        public:
            vector<vector<int>> levelOrder(TreeNode* root) {
                vector<vector<int>> result;
                deque<TreeNode*> dq;
                if(root == NULL) return result;
        
                dq.push_back(root);
        
                while(!dq.empty()){
                    vector<int> temp;
                    int levelNo = dq.size();
        
                    for(int i=0;i<levelNo;i++){  //USE OF A FOR LOOP FROM 0 TILL THE LEVEL NUMBER IN ORDER TO INSERT ELEMENT IN THE TEMP ARRAY WHICH LATER WILL BE INSERTED TO THE FINAL RESULT ARRAY
                        TreeNode* curr = dq.front();
                        dq.pop_front();
                        temp.push_back(curr->val);
        
                        if(curr->left != NULL) dq.push_back(curr->left);
                        if(curr->right != NULL) dq.push_back(curr->right);
                    }
                    result.push_back(temp);
                }
                return result;
            }
        };