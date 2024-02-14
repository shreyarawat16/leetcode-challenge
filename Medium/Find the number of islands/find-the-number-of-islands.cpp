//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  void bfs(int row, int col, vector<vector<char>> grid, vector<vector<int>>& vis, int n, int m)
    // Function to find the number of islands.
    {
        queue<pair<int,int>> q;
        vis[row][col]=1;
        q.push({row,col});
        
        
        while(!q.empty()){
            int r= q.front().first;
            int c= q.front().second;
            q.pop();
            for(int i=-1; i<=1; i++){
                for(int j=-1; j<=1; j++){
                    int nr= r+i;
                    int nc= c+j;
                    if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]=='1'){
                        vis[nr][nc]=1;
                        q.push({nr, nc});
                        
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int ans=0;
        int n= grid.size(), m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    ans++;
                    bfs(i,j,grid,vis,n,m);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends