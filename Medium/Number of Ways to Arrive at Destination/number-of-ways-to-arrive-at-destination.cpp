//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<vector<int>> adj[n];
        for(auto it: roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        vector<long long> dist(n, 1e18);
        vector<int> ways(n,0);
        ways[0]=1;
        dist[0]=0;
    int mod= (1e9+7);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
        greater<pair<long long, int>>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            long long d= pq.top().first;
            int node= pq.top().second;
            pq.pop();
            
            for(auto it: adj[node]){
               int v= it[0];
               long long w= it[1];
               if(d+w< dist[v]){
                   dist[v]= d+w;
                   
                   pq.push({dist[v], v});
                   ways[v]= ways[node]%mod;
               }
               else if(d+w== dist[v]){
                   ways[v]= (ways[v]+ways[node])%mod;
               }
            }
        }
        return (ways[n-1])%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends