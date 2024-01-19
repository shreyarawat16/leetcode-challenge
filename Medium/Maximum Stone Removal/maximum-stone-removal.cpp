//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class DisjointSet {
    
public:
vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findulpar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findulpar(parent[node]);
    }

   

    void unionbysize(int u, int v) {
        int ulp_u = findulpar(u);
        int ulp_v = findulpar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
        int maxrow=0, maxcol=0;
        for(auto it: stones){
            maxrow= max(maxrow, it[0]);
            maxcol= max(maxcol, it[1]);
        }
       
        unordered_map<int, int> mp;
        DisjointSet ds(maxrow+ maxcol+1);
        for(auto it: stones){
            int u= it[0];
            int v= it[1]+ maxrow+1;
            ds.unionbysize(u,v);
            mp[u]=1;
            mp[v]=1;
        }
        int cnt=0;
        for(auto it: mp){
            if(ds.findulpar(it.first)== it.first){
                cnt++;
            }
        }
        return n-cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends