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

//LEETCODE: 863

/*THINGS TO KEEP IN MIND:
1) we have to basically print the nodes at k level from the target node. (so this gives the intuition that BFS is needed).

2) But BFS can only travel downwards and not from the node to the parent node, so here we need to have a record of a node and
its parent node as well, so therefore an "inorder traversal" or "preorder traversal" and a hashmap would do the job.

3) while applying the BFS take care that apart from the curr->left and curr->right, we need to check the parent of curr as
well and push that to the queue, also keeping in mind that the nodes visited should not be inserted into the queue once again
so a set is used for that purpose.
*/

/*Given the root of a binary tree, the value of a target node target, and an integer k, 
return an array of the values of all nodes that have a distance k from the target node.
You can return the answer in any order.

Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.

Example 2:
Input: root = [1], target = 1, k = 3
Output: []*/

class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    void inorder(TreeNode* root) {
        if (root == NULL)
            return;

        if (root->left != NULL) parent[root->left] = root;
        
        if (root->right != NULL) parent[root->right] = root;
        
        inorder(root->left);
        inorder(root->right);
    }

    void BFS(TreeNode* target, int k, vector<int>& result){
        unordered_set<int> visited;
        deque<TreeNode*> dq;

        dq.push_back(target);
        visited.insert(target->val);

        while(!dq.empty()){
            int n = dq.size();

            if(k==0) break;

            while(n--){
                TreeNode* curr = dq.front();
                dq.pop_front();
                //left
                if((curr->left != NULL) && (visited.find(curr->left->val) == visited.end())){
                    dq.push_back(curr->left);
                    visited.insert(curr->left->val);
                }

                //right
                if(curr->right != NULL && (visited.find(curr->right->val) == visited.end())){
                    dq.push_back(curr->right);
                    visited.insert(curr->right->val);
                }

                //parent
                if((parent.find(curr) != parent.end()) && (visited.find(parent[curr]->val) == visited.end())){
                    dq.push_back(parent[curr]);
                    visited.insert(parent[curr]->val);
                }
            }
            k--;
        }

        while(!dq.empty()){
            result.push_back(dq.front()->val);
            dq.pop_front();
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        if(root==NULL) return result;
        inorder(root);

        BFS(target, k , result);
        return result;
    }
};