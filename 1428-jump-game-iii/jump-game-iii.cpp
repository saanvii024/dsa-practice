class Solution {
public:

    bool dfs(vector<int>& arr, int start, vector<bool>& vis) {

        int n = arr.size();

        // out of bounds
        if(start < 0 || start >= n)
            return false;

        // already visited
        if(vis[start])
            return false;

        // found zero
        if(arr[start] == 0)
            return true;

        vis[start] = true;

        int forward = start + arr[start];
        int backward = start - arr[start];

        return dfs(arr, forward, vis) ||
               dfs(arr, backward, vis);
    }

    bool canReach(vector<int>& arr, int start) {

        vector<bool> vis(arr.size(), false);
        return dfs(arr, start, vis);
    }
};