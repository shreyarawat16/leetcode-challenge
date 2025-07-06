class Solution {
  public:
  //count the number os subarrays where sum at most equal to target k(sum<=k)
  int solve(vector<int>& nums , int k){
      int l=0, r=0, sum=0, n= nums.size(), count=0;
      if(k<0) return 0;
      while(r<n){
          sum+= nums[r];
          while(sum>k){
              sum-= nums[l];
              l++;
          }
          count+= r-l+1;
          r++;
      }
      return count;
  }
    int numberOfSubarrays(vector<int>& arr, int target) {
        // Your code goes here.
        return solve(arr, target)- solve(arr, target-1);
    }
};