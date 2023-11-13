class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ind=-1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]== target){
                ind=i;
                break;
            }
        }
        if(ind==-1){
            return -1;
        }
        return ind;
    }
};