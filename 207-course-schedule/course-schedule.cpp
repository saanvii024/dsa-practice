class Solution {
public:

//this function is for dfs

    bool iscycle( int src, vector<bool>& vis, vector<bool>& rec, vector<vector<int>>& graph){
        vis[src]=true;
        rec[src]=true;

        for(int i = 0; i <graph.size(); i++){
            int u = graph[i][1];
            int v = graph[i][0];
            if(u == src){
                if(!vis[v]){
                    if(iscycle(v, vis, rec, graph)){
                        return true;
                    }

                } else {
                    if(rec[v]){
                        return true;
                    } 
                    
                }
            }
        }
        rec[src] = false; //backtracking
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& graph) {

        int V = numCourses; //vertex
        vector<bool> vis(V, false);
        vector<bool> rec(V, false); //recursion

        //q didnt mention if its connected or disconnected, we assume disconnected

        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(iscycle(i, vis, rec, graph)){
                    return false;
                } 
            }
        }
        //if no cycle, we can do topological sorting
        return true;
 
    }
};