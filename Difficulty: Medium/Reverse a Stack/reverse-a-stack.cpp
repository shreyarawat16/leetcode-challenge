class Solution {
  public:
  void insertAtBottom(int val, stack<int>& st){
      if(st.empty()){
          st.push(val);
          return;
      }
      int v=st.top();
      st.pop();
      insertAtBottom(val, st);
      st.push(v);
      return;
  }
    void reverseStack(stack<int> &st) {
        // code here
        if(st.empty()){
            return;
        }
        int val= st.top();
        st.pop();
        reverseStack(st);
        insertAtBottom(val,st);
        return;
    }
};