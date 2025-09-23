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
    
          

    string infixToPrefix(string &s) {
        // code here

        reverse(s.begin(), s.end());
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                s[i]=')';
            }
            else if(s[i]==')'){
                s[i] = '(';
            }
        }
        
          string ans="";
          stack<char> st;
          for(int i=0; i< s.size(); i++){
               char ch= s[i];
               if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')){
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
                 if(ch=='^'){
                   while(!st.empty() && precedence(ch)<= precedence(st.top()))
                   {
                     ans+= st.top();
                     st.pop();
                  }
                  
                }
                else{
                    while(!st.empty() && precedence(ch)< precedence(st.top()) ){
                        ans+= st.top();
                     st.pop();
                    }
                }
                st.push(ch);
             }
          }
          while(!st.empty()){
              ans+= st.top();
              st.pop();
          }
          
       reverse(ans.begin(), ans.end());
       return ans;
    }
};
