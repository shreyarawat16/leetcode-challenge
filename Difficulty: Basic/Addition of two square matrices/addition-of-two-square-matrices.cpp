// User function Template for C++

class Solution {
  public:
    void Addition(vector<vector<int>>& matrixA, vector<vector<int>>& matrixB) {
        // Code here
        int n1= matrixA.size(), m1= matrixA[0].size();
        int n2= matrixB.size(), m2= matrixB[0].size();
        if(n1==0 || n2==0 || m1==0 || m2==0){
            return;
        }
        for(int i=0; i<n1; i++){
            for(int j=0; j<m1; j++){
                matrixA[i][j]= matrixA[i][j]+ matrixB[i][j];
            }
        }
    }
};