class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
           int maxi= INT_MIN;
           int n=arr.size();
           int ans=0;
           for(int i=0; i<n; i++){
              if(arr[i]> maxi){
                  maxi= arr[i];
              }
              if(maxi==i){
                  ans++;
              }
           }
           return ans;
    }
};