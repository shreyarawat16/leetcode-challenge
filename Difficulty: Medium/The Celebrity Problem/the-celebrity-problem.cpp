class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        //TC
        int n= mat.size();
        vector<int> knowMe(n,0);
        vector<int> iKnow(n,0);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==1){
                    knowMe[j]++;
                    iKnow[i]++;
                }
            }
        }
        for(int i=0; i<n; i++){
            if(knowMe[i]== n && iKnow[i]==1){
                return i;
            }
        }
        return -1;
    }
};