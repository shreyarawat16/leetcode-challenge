class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // write code here
        int n= arr.size();
        vector<int> ans(n,1);
        stack<int> st;
        for(int i=0; i<n; i++){
          
            while(!st.empty() && arr[st.top()] <= arr[i]){
                
                st.pop(); 
            }
            if(st.empty()){
                ans[i]= i+1;
            }
            else{
                ans[i]=i-st.top();
            }
           
           st.push(i);
        }
        return ans;
    }
};