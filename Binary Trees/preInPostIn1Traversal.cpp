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

vector<int> preInPostTraversal(TreeNode* root){
    stack<pair<TreeNode*,int>> st;
    vector<int> pre,in,post;

    if(root == NULL) return;

    while(!st.empty()){
        auto it = st.top();
        st.pop();

        if(it.second == 1){
            pre.push_back(it.first -> val);
            it.second++;
            st.push(it);

            if(it.first -> left != NULL) st.push({it.first -> left,1});
        }

        else if(it.second == 2){
            in.push_back(it.first -> val);
            it.second++;
            st.push(it);

            if(it.first -> right != NULL) st.push({it.first -> right,1});
        }

        else{
            post.push_back(it.first -> val);
        }
    }
}