class Solution {
  public:
 void solve(int i,int sum, vector<int>& arr, vector<int>& ans){
     if(i==arr.size()){
         ans.push_back(sum);
         return;
     }
     //include
     sum+= arr[i];
     solve(i+1,sum,arr, ans );
     sum-=arr[i];
     //exclude
     solve(i+1, sum, arr, ans);
 }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int> ans;
        int i=0, sum=0;
       solve(i,sum,arr, ans);
       return ans;
    }
};