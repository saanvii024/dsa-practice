class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        //second [] is for if we have stock or no, 0 if no stock hold, 1 if we have stock
        vector<vector<int>> dp(n+1, vector<int> (2));
        dp[0][0] =  0;
        dp[0][1] = -prices[0]; //since we bought it, negative money
        for(int i = 1; i < n; i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i] - fee); //selling prev to get dp[i][0] presently
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        } //buying prev to dp[i][1]
        return dp[n-1][0];
        
    }
};