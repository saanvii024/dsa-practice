class Solution {
public:

    TreeNode* IS(TreeNode* root){

        while(root->left != NULL){
            root = root->left;
        }

        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

        if(root == NULL){
            return NULL;
        }

        if(key < root->val){

            root->left = deleteNode(root->left, key);

        } 
        else if(key > root->val){

            root->right = deleteNode(root->right, key);

        } 
        else {

            // CASE 1: no child
            if(root->left == NULL && root->right == NULL){

                delete root;
                return NULL;
            }

            // CASE 2: one child
            if(root->left == NULL || root->right == NULL){

                TreeNode* child =
                    (root->left != NULL) ? root->left : root->right;

                delete root;
                return child;
            }

            // CASE 3: two children

            TreeNode* successor = IS(root->right);

            root->val = successor->val;

            root->right =
                deleteNode(root->right, successor->val);
        }

        return root;
    }
};