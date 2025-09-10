// User function Template for C++
class DisjointSet{
    private:
    vector<int> size;
    vector<int> parent;
    public:
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
    }
    int findParent(int u){
        if(parent[u]==u){
            return u;
        }
        return findParent(parent[u]);
    }
    void UnionBySize(int u, int v){
        int pu= findParent(u);
        int pv= findParent(v);
        if(pu==pv){
            return;
        }
        if(size[pu]> size[pv]){
            parent[pv]=pu;
            size[pu]+= size[pv];
        }
        else{
            parent[pu]=pv;
            size[pv]+= size[pu];
        }
    }
};
class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<pair<int,int>> v;
          DisjointSet ds(V);
        for(int i=0; i<V; i++){   
           for(int j=0; j<V; j++){
               if(adj[i][j]==1){
                   int pu= ds.findParent(i);
                   int pv= ds.findParent(j);
                    if(pu!=pv){
                        ds.UnionBySize(i,j);
                    }
               }
           }
        }
      
        int cnt=0;
        for(int i=0; i<V; i++){
            if(ds.findParent(i)==i){
                cnt++;
            }
        }
        return cnt;
    }
};