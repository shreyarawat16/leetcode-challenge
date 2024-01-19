//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class DisjointSet {
    vector<int> rank, parent, size;
public:
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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n*m);
        int vis[n][m];
        memset(vis,0, sizeof(vis));
        vector<int> ans;
        int cnt=0;
       
    for(auto it: operators){
      int row=  it[0];
        int col= it[1];
        if(vis[row][col]==1){
            ans.push_back(cnt);
            continue;
        }
        
            vis[row][col]=1;
            cnt++;
             int delrow[]= {-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
            for(int i=0; i<4; i++){
                int nr= row+delrow[i];
                int nc= col+ delcol[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    
                 if(vis[nr][nc]==1){
                     int nodeno= row*m+col;
                     int nrno= nr*m+ nc;
                     if(ds.findulpar(nodeno)!= ds.findulpar(nrno)){
                         cnt--;
                         ds.unionbysize(nodeno, nrno);
                     }
                 }
                }
            }
        
        ans.push_back(cnt);
    }
    return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends