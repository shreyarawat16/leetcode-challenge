class Solution {
  public:
  void DFS(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& ans){
      vis[node]=1;
      ans.push_back(node);
      for(auto i: adj[node]){
          if(node==i) continue;
          if(!vis[i]){
              DFS(i, adj, vis, ans);
          }
      }
  }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int> ans;
        int n= adj.size();
       
        
        vector<int> vis(n,0);
        DFS(0,  adj, vis, ans);
        return ans;
    }
};