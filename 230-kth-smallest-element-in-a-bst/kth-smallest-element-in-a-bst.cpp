class Solution {
public:

    vector<int> sortt;
    void inorder(TreeNode* root){

        if(root == NULL){
            return;
        }
        inorder(root->left);
        sortt.push_back(root->val);
        inorder(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {

        inorder(root);
        return sortt[k-1];
    }
};