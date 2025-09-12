class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int> mp;
        int sum=0;
        int n= arr.size();
        int maxi=0;
        for(int i=0; i<n; i++){
            sum+= arr[i];
            int target= sum-k;
            if(target==0){
                maxi= max(maxi, i+1);
            }
           if(mp.find(target)!= mp.end()){
                  maxi= max(maxi, i-mp[target]);
            }
            if(mp.find(sum)== mp.end()){
            mp[sum]=i ;
            }            
        }
        return maxi;
    }
};