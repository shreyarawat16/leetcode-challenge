class Solution {
  public:
    int binarysearch(vector<int> &arr, int k) {
        // code here
        int low=0, high= arr.size()-1;
        int ans=-1;
        while(low<= high){
            int mid= (high+low)/2;
            if(arr[mid]==k){
                ans= mid;
                high=mid-1;
            }
            else if(k> arr[mid]){
                low= mid+1;
            }
            else{
                high= mid-1;
            }
        }
        return ans;
    }
};