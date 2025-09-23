// User function Template for C++

class Solution {
  public:
    string preToInfix(string pre_exp) {
        // Write your code here
        stack<string> st;
        for(int i= pre_exp.size()-1; i>=0; i--){
            char ch= pre_exp[i];
            if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')){
                string s(1,ch);
                st.push(s);
            }
            else{
                string left= st.top();
                st.pop();
                string right= st.top();
                st.pop();
                string s(1,ch);
                string newString= "("+ left+ s+right+")";
                st.push(newString);
            }
        }
        string ans="";
        while(!st.empty()){
            ans+= st.top();
            st.pop();
        }
        return ans;
    }
};