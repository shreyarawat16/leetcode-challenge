class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> set;
        vector<vector<int>> output;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                
                int low = j+1, high = n-1;
                 while(low < high){
                long long int sum= nums[low];
                sum+= nums[high];
                sum+= nums[i];
                sum+= nums[j];
              
                    if(sum < target){
                        low++;
                    }
                    else if(sum> target){
                        high--;
                    }
                    else{
                        set.insert({nums[i], nums[j], nums[low], nums[high]});
                        low++; high--;
                    }
                }
            }
        }
        for(auto it : set){
            output.push_back(it);
        }
        return output;
    }







};