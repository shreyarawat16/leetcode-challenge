class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        sort(arr.begin(), arr.end());
        int len=1;
        int maxi=1;
        int n= arr.size();
        for(int i=1; i<n; i++){
            if(arr[i]- arr[i-1] == 1){
                len++;
                
            }
            else if(arr[i]!=arr[i-1]){
                len=1;
            }
            maxi= max(maxi, len);
        }
        return maxi;
    }
};