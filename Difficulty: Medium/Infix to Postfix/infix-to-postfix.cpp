class Solution {
  public:
  int precedence(char ch){
      if(ch=='^'){
          return 3;
      }
      else if(ch=='*' || ch=='/'){
          return 2;
      }
      else if(ch=='+' || ch=='-'){
          return 1;
      }
      return -1;
  }
    string infixToPostfix(string& s) {
          string ans;
          stack<int> st;
          for(int i=0; i<s.size(); i++){
              char ch= s[i];
               if((ch>='a' and ch<='z') || (ch>='A' and ch<='Z') || (ch>='0' and ch<='9')){
                 ans= ans+ch;   
               }
               else if(ch=='('){
                 st.push(ch);
               }
               else if(ch==')'){
                 while(!st.empty() && st.top()!='('){
                     ans+= st.top();
                     st.pop();
                 }
                 st.pop();
               }
             else {
               while(!st.empty() && ((ch=='^' && precedence(ch)< precedence(st.top())) ||
               (ch!='^' && precedence(ch)<= precedence(st.top()))))     {
                 ans+= st.top();
                 st.pop();
              }
               st.push(ch);
             }
             
          }
          while(!st.empty()){
              ans+= st.top();
              st.pop();
          }
          return ans;
    }
};
