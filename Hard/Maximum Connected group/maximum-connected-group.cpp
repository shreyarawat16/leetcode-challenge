//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
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
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
       
          int ans=0;
        int n=grid.size();
        int nr[]={-1,0,1,0};
        int nc[]={0,-1,0,1};
        DisjointSet dis(n*n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                
            {   if(grid[i][j]==0) continue;
                int node=i*n+j;
                for(int k=0;k<4;k++)
                {
                    int adjr=i+nr[k];
                    int adjc=j+nc[k];
        
                    if(adjr>=0 && adjr<n && adjc>=0 && adjc<n && grid[adjr][adjc]==1)
                    {
                        int adjnode=adjr*n+adjc;
                        dis.unionbysize(node,adjnode);
                    }
                }
                
            }
        }
        //checking with 0-->1 cases
        
           for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {   if(grid[i][j]==1) continue;
               
                int node=i*n+j;
                    set<int> set;
                for(int k=0;k<4;k++)
                {
                    int adjr=i+nr[k];
                    int adjc=j+nc[k];
                    if(adjr>=0 && adjr<n && adjc>=0 && adjc<n && grid[adjr][adjc]==1)
                    {
                        int adjnode=adjr*n+adjc;
                        // dis.ubysize(node,adjnode);
                        set.insert(dis.findulpar(adjnode));
                    }
                    int temp=0;
                   for(auto i:set)
                   {
                       temp+=dis.size[i];
                   }
                   ans=max(ans,temp+1);
                }
                
            }
        }
        for(int cn=0;cn<n*n;cn++)
        {
            ans=max(ans,dis.size[dis.findulpar(cn)]);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends