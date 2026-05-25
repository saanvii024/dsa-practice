class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_tillnow = INT_MIN;
        int currmax = 0;

        for(int i = 0;i< nums.size();i++){
            currmax = max(nums[i], currmax + nums[i]);
            max_tillnow = max(max_tillnow, currmax);

        }
        return max_tillnow;
        
    }
};