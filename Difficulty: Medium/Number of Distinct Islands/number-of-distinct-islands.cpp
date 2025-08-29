// User function Template for C++

class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        set<set<pair<int,int>>> ans;
        
         queue<pair<int, int>> q;
         int dr[4]={-1,0,+1,0};
         int dc[4]= {0,+1,0,-1};
         int sr, sc;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                set<pair<int,int>> st;
                if(grid[i][j]==1 && !vis[i][j]){
                    q.push({i,j});
                    sr=i, sc=j;
                    vis[i][j]=1;
                   
        while(!q.empty()){
            int row= q.front().first;
            int col= q.front().second;
            q.pop();
            st.insert({row-sr, col-sc});
            for(int k=0; k<4; k++){
                int nr= row+ dr[k];
                int nc= col+ dc[k];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && !vis[nr][nc])
                     {
                        q.push({nr, nc});
                        vis[nr][nc]=1;
                       }                 
                }
           
            }
            ans.insert(st);
        }
   }
        }
     
           return ans.size();
    }
};
