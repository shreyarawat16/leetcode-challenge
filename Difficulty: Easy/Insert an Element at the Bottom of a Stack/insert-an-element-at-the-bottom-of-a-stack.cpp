// User function Template for C++

class Solution {
  public:
  void solve(stack<int>& st, int x){
       if(st.empty()){
            st.push(x);
            return;
        }
        int element= st.top();
        st.pop();
        solve(st,x);
        st.push(element);
        return;
  }
    stack<int> insertAtBottom(stack<int> st, int x) {
       solve(st, x);
        return st;
    }
};