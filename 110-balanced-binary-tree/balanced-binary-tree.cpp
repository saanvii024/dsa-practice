class Solution {
    int maxDiff = 0;
public:
    bool isBalanced(TreeNode* root) {
        helper(root, 0);
        return maxDiff <= 1;
    }
    
    int helper(TreeNode* node, int depth) {
        if (!node) return depth;
        
        int left = helper(node->left, depth + 1);
        int right = helper(node->right, depth + 1);
        
        maxDiff = max(maxDiff, abs(left - right));
        
        return max(left, right);
    }
};