// User function Template for C++
class DisjointSet{
    public:
    vector<int> parent;
    vector<int> size;
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
        return parent[u] = findParent(parent[u]);
    }
    void UnionBySize(int u, int v){
        int pu= findParent(u);
        int pv= findParent(v);
        if(pu==pv){
            return;
        }
        if(size[pu]> size[pv]){
            parent[pv]= pu;
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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<int> ans;
        int cnt=0;
        int dr[4]={-1,0,+1,0};
        int dc[4]={0,+1,0,-1};
        DisjointSet ds(n*m);
        for(auto it: operators){
            int row= it[0];
            int col= it[1];
            int node= row*m+col;
            if(!vis[row][col]){
                vis[row][col]=1;
                cnt++;
                for(int i=0; i<4; i++){
                    int nr= row+dr[i];
                    int nc=col+ dc[i];
                    int newNode= nr*m +nc;
                    if(nr>=0 && nc>=0 && nr<n && nc<m && vis[nr][nc]==1
                    && ds.findParent(newNode)!= ds.findParent(node)){
                        ds.UnionBySize(node, newNode);
                        cnt--;
                    }
                }
                
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
