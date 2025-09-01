class Solution {
  public:
  bool DFS(int start,vector<vector<int>> &edges, int V, vector<int>& vis,vector<int>& pathVis ){
      vis[start]=1;
      pathVis[start]=1;
      for(auto it: edges[start]){
         
          if(!vis[it]){
              if(DFS(it, edges, V, vis, pathVis)) {
                  return true;
              }
          }
          else if(pathVis[it]){
              return true;
          }
        
      }
      pathVis[start]=0;
      return false;
  }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int> vis(V,0);
        vector<int> pathVis(V,0);
        vector<vector<int>> adj(V);
        for(auto it: edges){
            int u= it[0];
            int v= it[1];
            adj[u].push_back(v);
            
        }
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(DFS(i, adj, V, vis,pathVis)== true){
                    return true;
                }
            }
        }
        return false;
    }
};