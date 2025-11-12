class Solution {
  public:
  
bool solve(int i, int target, vector<int>& arr, int n,vector<vector<int>>& dp){
    if(target==0){
        return true;
    }
    
    if(i==0){
        return arr[0]==target;
    }

    if(dp[i][target]!= -1){
        return dp[i][target];
    }
    //exclude
    bool notTake= solve(i-1,target, arr,n,dp);
    //include
    bool take= false;
    if(arr[i]<= target){
      take= solve(i-1, target-arr[i], arr,n,dp);
    }
   return dp[i][target]= (take || notTake);
    
}
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        // Code here
        int ind=n-1;
        vector<vector<int>> dp(n, vector<int>(k+1,-1));
        return solve(ind, k, arr, n, dp);//it signify that we are searching for target k
        //from oth index to n-1
    }
};