class Solution {
public:
void solve(vector<int> arr, vector<int> temp,  vector<vector<int>>& ans, int i){
   if(i== arr.size()){
       bool ispresent= find(ans.begin(), ans.end(), temp)!= ans.end();
       if(!ispresent){
           ans.push_back(temp);
       }
       
       return;
   }
   //exclude
   solve(arr, temp, ans, i+1);
   //include
temp.push_back(arr[i]);

solve(arr, temp,  ans, i+1);
temp.pop_back();
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());


        vector<int> temp;
        vector<vector<int>> ans;
        solve(nums, temp,  ans, 0);
        return ans;
    }
};