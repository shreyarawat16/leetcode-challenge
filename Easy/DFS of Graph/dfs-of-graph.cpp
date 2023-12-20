//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  vector<int> dfs(int s, int n, vector<int> adj[], int vis[], vector<int>& ans){
      
      vis[s]=1;
     
      ans.push_back(s);
      
          for(auto it:adj[s]){
              if(!vis[it]){
                  dfs(it,n,adj,vis,ans);
              
          }
      }
      return ans;
  }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int n, vector<int> adj[]) {
        // Code here
        int vis[n+1]={0};
     vector<int> ans;
       
       return dfs(0,n,adj, vis, ans);
                
            
        
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends