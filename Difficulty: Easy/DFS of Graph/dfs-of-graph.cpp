class Solution {
  public:
 void DFS(int start, vector<vector<int>>& adj,vector<int>& vis, vector<int>& ans ){
     vis[start]=1;
     ans.push_back(start);
     for(auto it: adj[start]){
         if(it == start){
             continue;
         }
         if(!vis[it]){
             DFS(it, adj, vis, ans);
         }
     }
 }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int> ans;
        int n= adj.size();
        vector<int> vis(n,0);
        
             DFS(0,adj, vis, ans);
      
        return ans;
    }
};