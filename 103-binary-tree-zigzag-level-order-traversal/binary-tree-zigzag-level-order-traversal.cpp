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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans; 
        if(!root) return ans; 

        queue<TreeNode*> q; // bfs uses a queue for level-by-level traversal
        q.push(root); 

        while(!q.empty()){
            int level_size = q.size(); // The size of the queue tells us exactly how many nodes are on the current level
            vector<int> lvlans;  // Temporary vector to store the values of the current level
            
            for(int i = 0; i < level_size; i++){
                TreeNode* node = q.front(); // For bfs to work properly, we process from the front and add to the rear
                q.pop();
                lvlans.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
            //check the current size of our final result vector to determine the level depth.
           
            if(ans.size() % 2 != 0){
                reverse(lvlans.begin(), lvlans.end());
                ans.push_back(lvlans);
            } else {
                //if even(left to right)
                ans.push_back(lvlans);
            }
        }

        return ans;
    }
};