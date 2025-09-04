// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int, int>>> adj(V);
        for(auto it: edges){
            int u= it[0];
            int v= it[1];
            int w= it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int> dist(V);
        for(int i=0; i<V; i++){
            dist[i]= 1e9;
        }
        dist[src]=0;
        
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int node= q.front();
            q.pop();
            for(auto it: adj[node]){
                int v= it.first;
                int wt= it.second;
                if(dist[node] + wt < dist[v]){
                    dist[v]= dist[node]+wt;
                    q.push(v);
                }
            }
        }
        return dist;
    }
};