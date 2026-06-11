class Solution {
public:
    int MOD = 1e9 + 7;
    int dfs(vector<vector<int>>& adj, int curr, int parent){
        int depth = 0;
        for(auto node : adj[curr]){
            if(node == parent) continue;
            depth = max(depth, dfs(adj, node, curr) + 1);
        }
        return depth;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int depth = dfs(adj, 1, 0);
        
        long long ans = 1; 
        while(--depth){
            ans = (ans * 2) % MOD;
        }
        return ans;
    }
};

//edges = [u,v] 
//weight 0 initially, assign either 1/2
//cost = total weight of all edges in path
//select x at max depth - dfs , we want total cost == odd
//find all the possibilities, so just assign 1 or 2 
//if depth = 3, we can assign 1,2 or 2,1 
//d = 4, 3 nodes = 1+1+1, 1+2+2, all permutations of these
//check only 1's, it has to be odd in number all the time 