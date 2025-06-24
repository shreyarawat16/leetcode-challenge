// User function Template for C++

class Solution {
  public:
  void insertAtBottom(stack<int>& st,  int x){
      if(st.empty()){
          st.push(x);
          return;
      }
      int val= st.top();
      st.pop();
      insertAtBottom(st,x);
      st.push(val);
      return;
  }
    void Reverse(stack<int> &St) {
        if(St.empty()){
        
            return;
        }
        int val= St.top();
        St.pop();
        Reverse(St);
        insertAtBottom(St, val);
        return;
   }
   
};