class Solution {
  public:
    string reverse(const string& S) {
        // code here
        string ans="";
        stack<char> st;
        int len= S.size();
        for(int i=0; i<len; i++){
            st.push(S[i]);
        }
        while(!st.empty()){
            char ch= st.top();
            st.pop();
            ans+= ch;
        }
        return ans;
    }
};