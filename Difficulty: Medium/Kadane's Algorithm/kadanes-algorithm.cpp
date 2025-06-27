class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Your code here
        //OPTIMAL- kadane algorithm
        int sum=0, n= arr.size(), maxi=INT_MIN;
        
        for(int i=0; i<n; i++){
            if(sum<0) sum=0;
         sum+= arr[i];
           maxi= max(maxi, sum);
        }
        
        return maxi;
        //BRUTE
        // int n= arr.size(), maxi=INT_MIN;
        
        // for(int i=0; i<n; i++){
        //   int sum=0;
        //     for(int j=i; j<n; j++){
        //     sum+= arr[j];
            
        //      maxi= max(maxi, sum);
        // }
           
        // }
        
        // return maxi;
    }
};