class Solution {
public:
   vector<vector<int>> res;
void solve(vector<int> array, vector<int> temp,
        vector<vector<int>>& res, int target, int i)
        {
            if(target==0){
                res.push_back(temp);
                return;
            }
            if(target<0){
                return;
            }
            if(i== array.size()){
                return;
            }
           //excluding
           solve(array, temp, res, target, i+1);
           //including
           temp.push_back(array[i]);
           solve(array, temp, res, target- array[i], i);
           temp.pop_back();
        }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        res.clear();
        vector<int> temp;
     
        solve(candidates, temp, res, target,0);
        return res;
    }
};