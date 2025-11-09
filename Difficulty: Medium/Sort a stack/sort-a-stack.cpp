class Solution {
  public:
  void sortedInsert(int val, stack<int>& st){
      if(st.empty() || (!st.empty() && val> st.top()) ){
          st.push(val);
          return;
      }
      int num= st.top();
      st.pop();
      sortedInsert(val, st);
      st.push(num);
  }
    void sortStack(stack<int> &st) {
        // code here
        if(st.empty()){
            
            return;
        }
        int val= st.top();
        st.pop();
        sortStack(st);
        sortedInsert(val, st);
    }
};
