#include <vector>
using namespace std;

class Solution {
public:
    bool dfs(int node, vector<bool>& vis, vector<bool>& path, vector<int> adj[]) {
        vis[node] = true;
        path[node] = true;
        
        for (int neighbor : adj[node]) {
            if (!vis[neighbor]) {
                if (dfs(neighbor, vis, path, adj)) {
                    return true;
                }
            } else if (path[neighbor]) {
                return true; // Cycle detected
            }
        }
        
        path[node] = false;
        return false;
    }
  
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> vis(V, false);
        vector<bool> path(V, false);
        
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, path, adj)) {
                    return true;
                }
            }
        }
        return false;
    }
};
