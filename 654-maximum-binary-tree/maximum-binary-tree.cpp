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

    TreeNode* helper(vector<int>& nums, int left, int right) {

        // base case
        if(left > right) {
            return NULL;
        }

        // find maximum element index
        int maxIndex = left;

        for(int i = left; i <= right; i++) {

            if(nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }

        // create root node
        TreeNode* root = new TreeNode(nums[maxIndex]);

        // build left subtree
        root->left = helper(nums, left, maxIndex - 1);

        // build right subtree
        root->right = helper(nums, maxIndex + 1, right);

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {

        return helper(nums, 0, nums.size() - 1);
    }
};