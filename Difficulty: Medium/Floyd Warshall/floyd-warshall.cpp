// User function template for C++

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        int n= dist.size();
        int m= dist[0].size();
        for(int val=0; val<n; val++){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
               if(dist[i][val]==1e8 || dist[val][j]==1e8 ){
                   continue;
               }   
               dist[i][j]= min(dist[i][j], dist[i][val]+ dist[val][j]);
              }
           }
        }
    }
};