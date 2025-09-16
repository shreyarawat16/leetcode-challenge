//Position this line where user code will be pasted.
class Solution {
  public:
  void DFS(int node, vector<int>& vis, vector<vector<int>>& adj, stack<int>& st){
      vis[node]=1;
      for(auto it: adj[node]){
          if(!vis[it]){
              DFS(it, vis, adj,st);
          }
      }
      st.push(node);
      
  }
   void DFS2(int node, vector<int>& vis, vector<vector<int>>& adj){
      vis[node]=1;
      for(auto it: adj[node]){
          if(!vis[it]){
              DFS2(it, vis, adj);
          }
      }
      
      
  }
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int n= adj.size();
        stack<int> st;
        vector<int> vis(n,0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                 DFS(i, vis, adj, st);
            }
        }
    
       vector<vector<int>> adjRev(n);
       for(int i=0; i<n; i++)
       {
           vis[i]=0;
          for(auto it: adj[i]){
              adjRev[it].push_back(i);
          }
       }
        
        int cnt=0;
        while(!st.empty()){
            int node= st.top();
            st.pop();
            if(!vis[node]){
                cnt++;
                DFS2(node, vis, adjRev);
            }
        }
        return cnt;
    }
};