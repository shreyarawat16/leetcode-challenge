class Solution {
  public:
    // Function to delete middle element of a stack.
    void solve(int cnt, stack<int>& st, int len){
        if(cnt== len/2){
            st.pop();
            return;
        }
        int num= st.top();
        st.pop();
        solve(cnt+1, st,len);
        st.push(num);
    }
    void deleteMid(stack<int>& s) {
        // code here..
        int i=0;
        int n= s.size();
        solve(i, s,n);
    }
};