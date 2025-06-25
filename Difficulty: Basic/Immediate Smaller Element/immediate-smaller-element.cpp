// User function template for C++
class Solution {
  public:
    void immediateSmaller(vector<int>& arr) {
       
        int n= arr.size();
        stack<int> st;
        st.push(-1);
        for(int i=n-1; i>=0; i--){
        if(st.top()< arr[i]){
            int temp= st.top();
            st.push(arr[i]);
            arr[i]= temp;
        }
        else{
            st.push(arr[i]);
            arr[i]=-1;
        }
             
            
        }
        
    }
};