class Solution {
public:
void solve(vector<int> arr, int k, vector<int> temp, vector<vector<int>>& res, int i){
   if(k==0){
      res.push_back(temp);
      return;
   }
   if(k<0 || i== arr.size()){
       return;
   }
   
   //include
   temp.push_back(arr[i]);
   solve(arr, k-arr[i], temp, res, i+1);
   temp.pop_back();
   //exclude
   while(i< arr.size()-1 && arr[i]== arr[i+1]){
       i++;
   }
   solve(arr, k, temp, res, i+1);
   
    
    
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        vector<vector<int>> res;
        solve(candidates, target, temp, res, 0);
        return res;
    }
};