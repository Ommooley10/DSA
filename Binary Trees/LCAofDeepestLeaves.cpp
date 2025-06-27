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

// LEETCODE: 1123
/*NOTE: A slight variation of the classic LCA problem, ithe p ani q nahi dile ahet, we have to find p and q, maybe there can be more nodes
i.e not just p and q and we have to find all of them.
ani te apan karu shakto prtyek node chi depth mojun, tyacha sathi map use kela ahe, jyachi jasti depth, to deepest leaf node.

mag tyacha varti lca lavaycha, prtyek node chi depth pahichi, jar ti maxDepth la match karat asel mhanjech to deepest leaf node ahe.
ani aata normal LCA wali conditions check karaychi i.e 1) if both are null 2) if one of them is null 3)bth are not null
*/

//QUESTION:
/*Given the root of a binary tree, return the lowest common ancestor of its deepest leaves.

Recall that:
The node of a binary tree is a leaf if and only if it has no children
The depth of the root of the tree is 0. if the depth of a node is d, the depth of each of its children is d + 1.
The lowest common ancestor of a set S of nodes, 
is the node A with the largest depth such that every node in S is in the subtree with root A.
 
Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]
Explanation: We return the node with value 2, colored in yellow in the diagram.
The nodes coloured in blue are the deepest leaf-nodes of the tree.
Note that nodes 6, 0, and 8 are also leaf nodes, but the depth of them is 2, 
but the depth of nodes 7 and 4 is 3.

Example 2:
Input: root = [1]
Output: [1]
Explanation: The root is the deepest node in the tree, and it's the lca of itself.

Example 3:
Input: root = [0,1,3,null,2]
Output: [2]
Explanation: The deepest leaf node in the tree is 2, the lca of one node is itself.*/

class Solution {
public:
    unordered_map<TreeNode*,int> storedDepth; //map to store depth of each node
    int maxDepth = 0;
    void depth(TreeNode* root, int d){ //func to store depth of each node in the map and at the same time update the maxDepth
        if(root == NULL) return;
        storedDepth[root] = d;
        maxDepth = max(maxDepth, d);
        depth(root->left, d+1);
        depth(root->right, d+1);
    }

    TreeNode* lca(TreeNode* root){ //apply LCA on the nodes having depth = maxDepth i.e the deepest leaf nodes
        if(root == NULL) return NULL;

        if(storedDepth[root] == maxDepth) return root;

        TreeNode* leftN = lca(root->left);
        TreeNode* rightN = lca(root->right);

        if(leftN != NULL && rightN != NULL) return root;
        if(leftN != NULL) return leftN;
        else return rightN;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        depth(root,0);

        return lca(root);
    }
};