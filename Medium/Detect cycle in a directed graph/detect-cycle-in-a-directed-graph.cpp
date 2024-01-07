//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    /*
    bool CheckDfs(int node, vector<int> adj[],int vis[],int pvis[]){
        vis[node] = 1;
        pvis[node]=1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                if(CheckDfs(it,adj,vis,pvis)==true)
                return true;
            }
             else if(pvis[it]==true)
                 return true;
           
        }
        pvis[node]=0;
        return false;
    }
    */
     
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        /*
        int vis[V]={0};
        int pvis[V]={0};
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
               if(CheckDfs(i,adj,vis,pvis)==true)
               return true;
              
            }
        }
        return false;
        */
        int indegree[V]= {0};
        for(int i=0; i<V;i++){
            for(auto it: adj[i]){
            indegree[it]++;
        }
        }
        queue<int> q;
        for(int i=0; i<V; i++){
            if(indegree[i]==0){
                q.push(i);
            }
            
        }
        vector<int> ans;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            ans.push_back(node);
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(ans.size()<V){
            return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends