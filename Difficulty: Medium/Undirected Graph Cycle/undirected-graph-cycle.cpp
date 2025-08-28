class Solution {
  public:
  bool DFS(int start, vector<vector<int>>& adj, vector<int>& vis, int parent ){
       vis[start]=1;
       for(auto it : adj[start]){
           if(!vis[it]){
              if( DFS(it, adj, vis, start)==true){
                  return true;
              }
           }
           else if(it!= parent){
               return true;
           }
       }
       return false;
  }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        int m= edges[0].size();
        vector<vector<int>> adj(V);
        vector<int> vis(V,0);
        for(auto it: edges){
            int u= it[0];
            int v= it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
      for(int i=0; i<V; i++){
         if(!vis[i] && DFS(i, adj, vis, -1)){
        return true;
      }
}
        return false;
    }
};