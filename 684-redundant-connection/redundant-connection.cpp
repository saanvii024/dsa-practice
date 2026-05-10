#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    // This 'parent' array stores the "Team Leader" for each node
    vector<int> parent;

    // The 'find' function: looks for the ultimate root/leader of a node
    int find(int i) {
        if (parent[i] == i)
            return i;
        // Path Compression: this line makes the code super fast by 
        // connecting the node directly to its ultimate leader.
        return parent[i] = find(parent[i]);
    }

    // The 'unite' function: joins two teams together
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);

        if (root_i != root_j) {
            // If they have different leaders, merge them
            parent[root_i] = root_j;
            return true;
        }
        // If they have the same leader, they are already connected!
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        // Initialize: every node is its own leader at the start
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0); // Fills parent as [0, 1, 2, 3...]

        for (auto& edge : edges) {
            // Try to unite the two nodes in the edge
            // If unite returns false, it means a cycle is detected
            if (!unite(edge[0], edge[1])) {
                return edge;
            }
        }

        return {};
    }
};