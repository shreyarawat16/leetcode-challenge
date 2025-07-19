class Solution {
  public:


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
       queue<pair<int,int>> q;
       for(int i=0; i<V; i++){
           if(!vis[i]){
                vis[i]=1;
               q.push({i,-1});
           
           while(!q.empty()){
           int u= q.front().first;
           int parent= q.front().second;
           q.pop();
           for(auto it: adj[u]){
               if(!vis[it]){
                   vis[it]=1;
                   q.push({it,u});
               }
               else if(it!= parent){
                   return true;
               }
           }
           
       }
       }
       }
      
       
       
        return false;
    }
};