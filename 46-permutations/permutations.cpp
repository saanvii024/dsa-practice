class Solution {
public:

    vector<vector<int>> ans;

    void solve(int idx, vector<int>& nums) {

        // base case
        if(idx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for(int i = idx; i < nums.size(); i++) {

            swap(nums[idx], nums[i]);

            solve(idx + 1, nums);

            // backtrack
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        solve(0, nums);

        return ans;
    }
};