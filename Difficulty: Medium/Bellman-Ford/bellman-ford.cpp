// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        
          vector<int> dist(V, 1e8);
        dist[src]=0;
        for(int i=0; i<V; i++){
        for(auto& it: edges){
            int u= it[0];
            int v = it[1];
            int wt= it[2];
            if(dist[u]!= 1e8 && dist[u]+wt< dist[v]){
                if(i==V-1){
                    return {-1};
                }               
                dist[v]= dist[u]+wt;
            }
         }
      }
    //  If after V-1 relaxations we can still relax, it means there’s a negative cycle.
         
        return dist;
    }
};
