class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<unsigned long long>>dp(n+1, vector<unsigned long long>(amount+1, 0)); //v imp initialization

//this loop is for the 1st col, 1st row, if no coints then no possible combinations so 0, but if col/amount = 0 we have 1 possibility of choosing no coins, so we just reinitialize the first column with 1 possibility
        for(int i = 0; i < n+1; i++){
            dp[i][0] = 1;
        }
        for(int i = 1; i < n + 1; i++){
            for(int j = 1; j < amount +1 ; j++){
                if(coins[i-1] <= j){ //valid
                    //include + exclude ( since we dont want max, we want all possible combinations here)
                    dp[i][j]=dp[i][j - coins[i-1]] + dp[i-1][j];
                } else { //if invalid
                    dp[i][j] = dp[i-1][j];
                }


            }
        }
        return dp[n][amount];
        
    }
};