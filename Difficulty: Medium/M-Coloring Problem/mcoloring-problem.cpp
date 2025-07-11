class Solution {
  public:
  bool ispossible(int node, vector<int>& color, int m, int n, vector<vector<int>>& graph){
      for(int i=0; i<n; i++){
          if(graph[node][i]==1 && color[i]==m) return false;
      }
      return true;
  }
  bool solve(int node, vector<vector<int>>& graph, int n, int m, vector<int>& color){
     //base case
     if(node == n){
         return true;
     }
      for(int i=1; i<=m; i++){
          if(ispossible(node,color, i,n, graph)){
              color[node]=i;
              if(solve(node+1, graph, n, m, color)) return true;
              color[node]=0;
          }
      }
      return false;
  }
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        vector<vector<int>> graph(v, vector<int>(v,0));
        for(int i=0; i<edges.size(); i++){
            graph[edges[i][0]][edges[i][1]]=1;
            graph[edges[i][1]][edges[i][0]]=1;
        }
        vector<int> color(v,0);
        return solve(0,graph,v,m, color);
    }
};