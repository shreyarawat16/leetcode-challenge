// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int, int>>> adj(V);
        for(auto it: edges){
            int u= it[0];
            int v= it[1];
            int wt= it[2];
            adj[u].push_back({v,wt});
        }
        vector<int> dist(V, INT_MAX);
        dist[0]=0;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int node= q.front();
            q.pop();
            for(auto it: adj[node]){
                int v= it.first;
                int w= it.second;
                if(dist[node]+ w< dist[v]){
                    dist[v]= dist[node]+w;
                    q.push(v);
                }
            }
        }
        for(int i=0; i<V; i++){
            if(dist[i]== INT_MAX){
                dist[i]=-1;
            }
        }
        return dist;
    }
};
