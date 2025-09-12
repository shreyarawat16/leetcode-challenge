// User function template for C++
class Solution {
  public:
    vector<int> findSubarray(vector<int>& arr) {
        // code here
        vector<int> ans;
        int n= arr.size();
        int sum=0, maxi=INT_MIN;
        int startInd=-1, endInd=-1, start=-1;
        for(int i=0; i<n; i++){
            
            if(arr[i]>=0){
                if(sum==0 ){
                    start=i;
                }
                sum+= arr[i];
                if(sum>= maxi){
                    maxi=sum;
                    endInd=i;
                    startInd= start;
                }
              
            }
            else{
                sum=0;
            }
        }
        if(startInd==-1 && endInd==-1){
            return {-1};
        }
        for(int i=startInd; i<=endInd; i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};