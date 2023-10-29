class Solution {
public:
void solve( vector<int>& temp, vector<vector<int>>& ans, int i,int n, int k, int sum){
    if(temp.size()==k){
        if(n==sum){
            ans.push_back(temp);
        }
        return;
    }
   if(i==10){
       return;
   }
    //include
   for(int ind=i; ind<=9; ind++){
    temp.push_back(ind);
    solve( temp, ans, ind+1,n,k,sum+ind);
    temp.pop_back();
   }
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>> ans;
       
        solve( temp, ans,1,n,k,0);
        return ans;
    }
};