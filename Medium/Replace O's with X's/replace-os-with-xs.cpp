//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
   void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid, int delrow[], int delcol[],int n,int m){
        vis[row][col]=1;
     
        for(int i=0; i<4; i++){
            int nr= row+delrow[i];
            int nc= col+delcol[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]=='O'){
                dfs(nr,nc,vis,grid,delrow,delcol,n,m);
            }
        }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>> vis(n, vector<int>(m,0));
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        //traverse first and last row
            for(int j=0; j<m; j++){
                //first row
                if( !vis[0][j] && mat[0][j]=='O' ){
                   dfs(0,j,vis,mat, delrow, delcol,n,m);
                }
                //last row
                if(!vis[n-1][j] && mat[n-1][j]=='O'){
                    dfs(n-1,j,vis,mat, delrow, delcol,n,m);
                }
                }
           //traverse first and last column
            for(int i=0; i<n; i++){
                //first column
                if( !vis[i][0] && mat[i][0]=='O' ){
                   dfs(i,0,vis,mat, delrow, delcol,n,m);
                }
                //last column
                if(!vis[i][m-1] && mat[i][m-1]=='O'){
                    dfs(i,m-1,vis,mat, delrow, delcol,n,m);
                }
                }
            
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && mat[i][j]=='O'){
                    mat[i][j]='X';
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends