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
public:
    int dfs(TreeNode* node, int curr){
        if(node==NULL) return 0;

        curr= curr*10 + node->val;

        //left

        if(!node->left && !node->right){ //then its a leaf node, no children at all
            return curr;
        }

        return dfs(node->left, curr) + dfs(node->right,curr);
    }

    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
        
    }
};