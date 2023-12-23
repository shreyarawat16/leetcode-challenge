//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  void bfs(int row, int col, vector<vector<char>> grid, vector<vector<int>>& vis){
    vis[row][col]=1;
    queue<pair<int, int>> q;
    q.push({row,col});
    int n=grid.size();
    int m=grid[0].size();
    while(!q.empty()){
   int r= q.front().first;
   int c= q.front().second;
   q.pop();
   for(int deltarow=-1; deltarow<=1; deltarow++){
       for(int deltacol=-1; deltacol<=1; deltacol++){
          int nrow= r+deltarow;
        int ncol=c+deltacol;
           if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
               vis[nrow][ncol]=1;
               q.push({nrow, ncol});
           }
       }
   }
    }
}
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
         int n= grid.size();
        int m= grid[0].size();
        int cnt=0;
        vector<vector<int>> visited(n, vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                      cnt++;
                    bfs(i,j,grid,visited);
                  
                }
            }
        }
        return cnt;
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