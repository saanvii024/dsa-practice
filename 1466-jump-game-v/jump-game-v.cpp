class Solution {
public:
    int dfs(int i, vector<int>& arr, int d, vector<int>& dp) {
        //memoization
        if (dp[i] != -1)
            return dp[i];

        //min best is 1 visited index
        int best = 1;
        int n = arr.size();

        //going forward and the constraint is that it should not go beyond array and also beyond d
        for (int nxt = i + 1; nxt <= min(n - 1, i + d); nxt++) {
            if (arr[nxt] >= arr[i])
                break; //wall in between 

            best = max(best, 1 + dfs(nxt, arr, d, dp));
        }
        //going backward
        for (int nxt = i - 1; nxt >= max(0, i - d); nxt--) {
            if (arr[nxt] >= arr[i])
                break;

            best = max(best, 1 + dfs(nxt, arr, d, dp));
        }
        //returning the best for this particular index
        return dp[i] = best;
    }

    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, -1);

        int ans = 1;
        //check all starting points
        for (int i = 0; i < n; i++) {
            ans = max(ans, dfs(i, arr, d, dp));
        }

        return ans;
    }
};