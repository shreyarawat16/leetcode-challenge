// User function Template for C++
class Disjoint{
    private:
    vector<int> size;
    vector<int> parent;
    public:
    Disjoint(int n){
        size.resize(n,1);
        parent.resize(n);
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
    }
    
    int findPar(int node){
    if(parent[node]== node){
        return node;
    }
    return findPar(parent[node]);
   }
   void UnionBySize(int u, int v){
       int pu= findPar(u);
       int pv= findPar(v);
        if(pu== pv){
            return;
        }
            if(size[pu]> size[pv]){
                parent[pv]=pu;
                size[pu]+= size[pv];
            }
           
            else{
                parent[pu]=pv;
                size[pv]+=size[pu];
            }
   }
};
class Solution {
  public:
static bool compare(vector<int> a,vector<int> b ){
    return a[2] < b[2];
}
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
       Disjoint ds(V);
       int ans=0;
      sort(edges.begin(), edges.end(), compare);
      for(auto it:edges){
          int u= it[0];
          int v= it[1];
          int wt= it[2];
      
           int pu= ds.findPar(u);
           int pv= ds.findPar(v);
           if(pu!= pv){
               ds.UnionBySize(u,v);
               ans+= wt;
             
           }
        }
        return ans;
    }
};