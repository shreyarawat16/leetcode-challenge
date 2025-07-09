class Solution {
  public:

  void solve(vector<vector<int>>& maze,vector<vector<int>>& vis,int r, int c, int n, int m, string& path,
  vector<string>& ans, int dr[], int dc[] ){
      if(r==n-1 && c==m-1){
          ans.push_back(path);
          return ;
      }
  vis[r][c]=1;
  string dname= "URDL";
  for(int i=0; i<4; i++){
      int nr= r+ dr[i];
      int nc= c+dc[i];
      if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && maze[nr][nc]==1){
          vis[nr][nc]=1;
          path.push_back(dname[i]);
          solve(maze, vis, nr, nc,n,m,path, ans, dr, dc);
          path.pop_back();
          vis[nr][nc]=0;
      }
    }
  } 
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int n= maze.size();
        int m= maze[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        string path="";
        vector<string> ans;
        int dr[]={-1,0,+1,0};
        int dc[]= {0,+1,0,-1};
        if(maze[0][0]==1){
           solve(maze,vis,0,0,n,m, path, ans, dr, dc);
        }
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};