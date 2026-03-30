/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int diam =0;

public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return diam;
        
    }
    int dfs(TreeNode* node){
        if(node==NULL) return 0;
        int l = dfs(node->left);
        int r = dfs(node->right);

        diam = max(diam,l+r);
        return 1+ max(l,r);
    }

};