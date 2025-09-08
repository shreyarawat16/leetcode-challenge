class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adj(V);
        for(auto it: edges){
            int u= it[0];
            int v= it[1];
            int wt= it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        int minDist=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        vector<int> vis(V,0);
        while(!pq.empty()){
           int d= pq.top().first;
           int node= pq.top().second;
           pq.pop();
           if(!vis[node]){
            vis[node]=1;
            minDist+= d;
           }
           for(auto it : adj[node]){
               int v= it.first;
               int wt= it.second;
               if(!vis[v]){
                 pq.push({wt,v});
               }
           }
        }
        return minDist;
    }
};