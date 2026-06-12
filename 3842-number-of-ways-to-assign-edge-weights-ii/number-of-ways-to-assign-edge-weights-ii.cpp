class Solution {
public:
    const int MOD = 1e9 + 7 ; 
    vector<int> level;
    vector<vector<int>> dp;
    vector<int> par ; 
    vector<vector<int>> adj ; 

    void buildDfs( int node , int lvl ) {
        level[node] = lvl ; 
        for ( auto i : adj[node] ) {
            buildDfs(i,lvl+1) ; 
        }
        return ; 
    }
    void buildJumpTable(int n ) {
        for ( int i = 1 ; i < n ; i ++ ) {
            dp[0][i] = par[i] ;  
        }
        for ( int i = 1 ; i < 17 ; i ++ ) {
            for ( int j = 1 ; j < n ; j ++ ) {
                dp[i][j] = dp[i-1][dp[i-1][j]] ; 
            }
        }
    }
    int lca ( int u , int v ) {
        if ( level[u] > level[v] ) swap(u,v) ; 
        int k = level[v] - level[u] ; 
        for ( int i = 17 ; i >= 0 ; i -- ) {
            int mask = ( 1 << i ) ; 
            if ( k & mask ) v = dp[i][v] ; 
        }
        if ( u == v ) return u ; 
        for ( int i = 16 ; i >= 0 ; i -- ) {
            int up = dp[i][u] , vp = dp[i][v] ; 
            if ( up != vp ) {
                u = up ;
                v = vp ; 
            }
        }
        return dp[0][u] ; 
    }
    int pow ( long long base , long long power ) {
        int res = 1 ; 
        base = base % MOD ; 
        while ( power > 0 ) {
            if ( power & 1 ) {
                res = (res * base) % MOD ; 
            }
            base = ( base %MOD * base%MOD ) % MOD ; 
            power >>= 1 ; 
        }
        return (int)(res % MOD) ; 
    }
    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {
        int n = edges.size() + 2;
        level.assign(n, 0);
        dp.assign(17, vector<int>(n, 0));
        par.assign(n,0) ; 
        adj.assign(n+1,vector<int>()) ;
        bool flag = false ;  
        for(auto i:edges) {
            if ( i[1] == 1 ) {
                flag = true ; break ; 
            }
        }
        for ( auto i : edges ) {
            int u = i[0] , v=i[1] ; 
            if ( flag ) {adj[v].push_back(u) ; par[u] = v ;} 
            else { adj[u].push_back(v) ; par[v] = u ; } 
        }
        buildDfs(1,0) ; 
        buildJumpTable(n) ; 
        vector<int> ans ; 
        for ( auto i : queries ) {
            int u = i[0] , v = i[1] ;
            if ( u == v ) {
                ans.push_back(0) ; 
                continue ; 
            }
            int mid = lca ( u , v ) ; 
            int dis ; 
            if ( mid == 1 ) {
                dis = level[u] + level[v] ; 
            } else {
                dis = level[u] + level[v] - 2 * level[mid] ; 
            }
            // cout << u << " " << v << " " << mid << " " << dis << endl ; 
            ans.push_back( pow(2,dis-1) % MOD ) ; 
        }
        return ans ; 
    };
};