class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        // code here
        int n= arr.size();
        int low=0, high=n-1;
        while(low<=high){
            int mid= (low+high)/2;
            if(arr[mid]< target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};
