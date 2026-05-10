class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -1);

        //base case
        dp[0] = 0;

//iterate through each j that we want to reach
        for(int j = 1; j < n; j++){
            //look bck at prev idxs

            for(int i = 0; i < j; i++){

                //can we reach i?
                //is the jump allowed

                long long diff = (long long)nums[j] - nums[i];
                if(dp[i]!= -1 && diff <= target && diff >= -target){

                    dp[j] = max(dp[j], dp[i] + 1);
                }

            }
        }
        //return value at last indexwhy 
        return dp[n-1];
        
    }
};


//let dp[j] be max jumps to reach index j
//base case dp[0]=0
//initialize dp values to -1

//look back at every possible prev idx i
//check constraint , if both true, that i<j and target >=nums j - i  and is it reachable? dp[i]! = -1 then dp[j] = max(dp[j], dp[i]+1)
