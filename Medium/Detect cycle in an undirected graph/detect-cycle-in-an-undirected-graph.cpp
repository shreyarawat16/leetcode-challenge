//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
     private:
    bool solve(const vector<int> adj[], int vis[], int src, int prev)
    {
        vis[src] = 1;
        for(auto i:adj[src])
        {
            if(i==prev) // If its a parent node continue.
            continue;
            
            if(vis[i]==1) // If already visited return true.
            return true;
            
            else
            {
                vis[i] = 1;
                if(solve(adj, vis, i, src)) // If true encountered anywhere keep returning true.
                return true;
            }
        }
     return false; // If traversed successfully return false.
    }
  
  
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V] = {0};
        
        for(int i=0; i<V; ++i)
        {
            if(vis[i]!=1)
            {
                if(solve(adj, vis, i, -1))
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends