/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int size = 1;
        int level = 0;
        int prev = INT_MIN;
        while (!q.empty()) {
            while (size > 0) {
                if (level % 2 == 0) {
                    if (q.front()->val % 2 == 0 || q.front()->val <= prev)
                        return false;
                    prev = q.front()->val;
                } else {
                    if (q.front()->val % 2 == 1 || q.front()->val >= prev)
                        return false;
                    prev = q.front()->val;
                }
                if (q.front()->left)
                    q.push(q.front()->left);
                if (q.front()->right)
                    q.push(q.front()->right);
                q.pop();
                size--;
            }
            size = q.size();
            level++;
            prev = (level % 2 == 0) ? INT_MIN : INT_MAX;
        }
        return true;
    }
};