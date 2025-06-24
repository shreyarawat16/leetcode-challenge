class Solution {
  public:
    int countMinReversals(string s) {
        // code here
        int n= s.size();
        if(n%2!=0) return -1;
        stack<char> st;
        for(int i=0; i<n; i++){
            char ch= s[i];
            if(ch== '{'){
                st.push(ch);
            }
            else{
                if(!st.empty() && st.top()=='{'){
                    st.pop();
                }
                else{
                    st.push(ch);
                }
            }
        }
        int open=0, close=0;
        while(!st.empty()){
            if(st.top()=='{'){
                open++;
            }
            else{
                close++;
            }
            st.pop();
        }
        return (open+1)/2 + (close+1)/2;
    }
};