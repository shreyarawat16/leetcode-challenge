class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n= arr.size();
        int presum=0;
        unordered_map<int, int> mp;
        
       
        int maxi=0;
        for(int i=0; i<n; i++){
            presum+= arr[i];
            int target= presum-k;
            if(presum==k){
                maxi= max(maxi, i+1);
            }
            
            if(mp.find(target)!= mp.end()){
                maxi= max(maxi,i-mp[target]);
            }
            if(mp.find(presum)== mp.end()){
            mp[presum]=i;
            }
        }
        return maxi;
    }
};