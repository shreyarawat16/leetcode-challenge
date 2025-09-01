class Solution {
  public:
 void dfs(int node,  vector<vector<int>>& adj, vector<int>& vis, stack<int>& st){
     vis[node]=1;
     for(auto it: adj[node]){
         if(!vis[it]){
             dfs(it, adj, vis, st);
         }
        
     }
     st.push(node);
 }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> vis(V);
        vector<vector<int>> adj(V);
        for(auto it: edges){
            int u= it[0];
            int v= it[1];
            adj[u].push_back(v);
        }
        stack<int> st;
        vector<int> ans;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i,adj, vis,st);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
        
    }
};