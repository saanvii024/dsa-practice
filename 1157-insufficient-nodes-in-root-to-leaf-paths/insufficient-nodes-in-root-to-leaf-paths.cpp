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
    TreeNode* solve(TreeNode* node ,int sum, int limit){
        if(node==NULL) return NULL;

        sum+= node->val;

        if(node->left== NULL && node->right==NULL){

            if(sum<limit){
                return NULL;
            } else return node;
        }

        node->left = solve(node->left, sum, limit);
        node->right = solve(node->right,sum,limit);

        if(node->left==NULL && node->right==NULL){
            return NULL;
        }
        return node;
    }

    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return solve(root,0,limit);  //intialize sum =0
    }
};

//postorder traversal(need info from child before deciding)
//path ka sum>=limit