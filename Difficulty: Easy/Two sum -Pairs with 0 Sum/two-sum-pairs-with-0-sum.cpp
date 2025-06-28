// User function template for C++

class Solution {
  public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        // code here
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        set<pair<int,int>> st;
        
        int n= arr.size(), sum=0;
        int i=0, j=n-1;
        while(i<j){
          
           sum= arr[i]+arr[j];
           if(sum<0){
               i++;
           }
           else if(sum>0){
               j--;
           }
           else{
               st.insert({arr[i], arr[j]});
               
               i++; j--;
           }
          
        }
        
          for(auto it: st){
               vector<int> temp;
               temp.push_back(it.first);
               temp.push_back(it.second);
                res.push_back(temp);
           }
           
          
         
        return res;
    }
};