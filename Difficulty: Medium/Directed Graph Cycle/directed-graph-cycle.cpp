class Solution {
  public:
//   bool DFS(int start,vector<vector<int>> &edges, int V, vector<int>& vis,vector<int>& pathVis ){
//       vis[start]=1;
//       pathVis[start]=1;
//       for(auto it: edges[start]){
         
//           if(!vis[it]){
//               if(DFS(it, edges, V, vis, pathVis)) {
//                   return true;
//               }
//           }
//           else if(pathVis[it]){
//               return true;
//           }
        
//       }
//       pathVis[start]=0;
//       return false;
//   }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        //USING TOP
        vector<int> vis(V,0);
        vector<int> pathVis(V,0);
        vector<vector<int>> adj(V);
        queue<int> q;
        for(auto it: edges){
            int u= it[0];
            int v= it[1];
            adj[u].push_back(v);
            
        }
        vector<int> indegree(V);
        for(int i=0; i<V; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        for(int i=0; i<V; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            topo.push_back(node);
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
      if(topo.size()==V){
          return false;
      }
      return true;
    }
};