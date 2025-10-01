class Solution {
  public:
    // Function to delete middle element of a stack.
    void solve(stack<int>& st, int count, int n){
        if(count== n/2){
            st.pop();
            return;
        }
        int val= st.top();
        st.pop();
        count++;
        solve(st, count, n);
        st.push(val);
        return;
    }
    void deleteMid(stack<int>& s) {
        // code here..
        int n= s.size();
        solve(s,0,n);
        return;
    }
};