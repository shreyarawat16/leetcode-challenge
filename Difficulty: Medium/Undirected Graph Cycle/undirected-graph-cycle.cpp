class Solution {
  public:

bool DFS(int node, vector<int>& vis, vector<vector<int>>& adj, int V, int parent){
     vis[node]=1;
    
     for(auto it: adj[node]){
            if(!vis[it]){
               if( DFS(it,vis, adj, V,node)) return true;
            }
             else if(it!= parent){
             return true;
            }
         
         
     }
     return false;
 }
    bool isCycle(int V, vector<vector<int>> edges) {
        // Code here
       
        vector<int> vis(V,0);
       vector<vector<int>> adj(V);
       for(int i=0; i<edges.size(); i++){
          int u= edges[i][0];
          int v= edges[i][1];
          adj[u].push_back(v);
          adj[v].push_back(u);
       }
       
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(DFS(i, vis, adj,V,-1)==true){
                    return true;
                }
            }
        }
        return false;
    }
};