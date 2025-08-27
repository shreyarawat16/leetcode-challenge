
class Solution {
  public:
  void DFS(int node, vector<vector<int>>& edges, int V, vector<int>& vis, vector<int>& temp){
      vis[node]=1;
      temp.push_back(node);
      for(auto it: edges[node]){
          if(it== node){
              continue;
          }
         if(!vis[it]){
              DFS(it, edges, V,vis, temp);
          }
      }
  }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> vis(V,0);
        vector<vector<int>> ans;
        vector<vector<int>> adjList(V);
        for(auto it : edges){
            
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        for(int i=0; i<V; i++){
            if(!vis[i]){
                vector<int> temp;
                DFS(i, adjList,V, vis, temp);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
