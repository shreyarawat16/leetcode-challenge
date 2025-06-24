class Solution {
  public:
  void solve(stack<int>& st, int mid, int index){
      if(index==mid){
          st.pop();
          return;
      }
      int val =st.top();
      st.pop();
      index++;
      solve(st, mid, index);
      st.push(val);
      return;
  }
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& s) {
        // code here..
        int n= s.size();
        int mid= n/2 ;
        solve(s, mid, 0);
        return;
        
    }
};