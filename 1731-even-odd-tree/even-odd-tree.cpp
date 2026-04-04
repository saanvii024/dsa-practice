class Solution {
public:
    bool check(TreeNode* root) {
        if (root == NULL) return true;

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            int prev = (level % 2 == 0) ? INT_MIN : INT_MAX;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (level % 2 == 0) {
                    if (node->val % 2 == 0 || node->val <= prev) {
                        return false;
                    }
                }

                else {
                    if (node->val % 2 != 0 || node->val >= prev) {
                        return false;
                    }
                }

                prev = node->val;

                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
            
            level++;
        }
        return true;
    }

    bool isEvenOddTree(TreeNode* root) {
        return check(root);
    }
};