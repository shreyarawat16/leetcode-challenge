class Solution {
    private:
    int presidency(char ch){
        if(ch=='+' or ch=='-'){
            return 1;
        }
        if(ch=='*' or ch=='/')
        return 2;
        if(ch=='^')
        return 3;
        return -1;
    }
  bool   isRightAssociative(char ch){
      return (ch=='^');
  }
  public:
    string infixToPrefix(string &s) {
        // code here
        string ans="";
        string rev= s;
        reverse(rev.begin(), rev.end());
        stack<char> st;
        for(char &ch: rev){
            if(ch=='('){
                ch=')';
            }
            else if(ch==')'){
                ch='(';
            }
        }
        for(char ch: rev){
            if(ch=='*' or ch=='/' or ch=='+' or ch=='-' or ch=='^'){
                while(!st.empty() and  st.top()!='(' and ((!isRightAssociative(ch) and presidency(st.top())>presidency(ch)) or  (isRightAssociative(ch) && presidency(st.top())>=presidency(ch)))) {
                    ans= ans+ st.top();
                    st.pop();
                }
                st.push(ch);
            }
            else if(ch>='a' and ch<='z' or ch>='A' and ch<='Z' or ch>='0' and ch<='9'){
                ans= ans+ch;
                
            }
            else if(ch=='('){
                st.push(ch);
            }
            else{
                //normal 
                while(st.top()!='('){
                    ans= ans+st.top();
                    st.pop();
                }
                st.pop();
            }
        }
        while(!st.empty()){
            ans= ans+st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};