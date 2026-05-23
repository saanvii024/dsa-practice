class Solution {
public:

    map<int,int> m;

    void dfs(TreeNode* root) {

        if(root == NULL) {
            return;
        }

        m[root->val]++;

        dfs(root->left);
        dfs(root->right);
    }

    vector<int> findMode(TreeNode* root) {

        dfs(root);

        int maxx = 0;

        vector<int> ans;

        // find maximum frequency
        for(auto i : m) {
            maxx = max(maxx, i.second);
        }

        // collect all modes
        for(auto i : m) {

            if(i.second == maxx) {
                ans.push_back(i.first);
            }
        }

        return ans;
    }
};