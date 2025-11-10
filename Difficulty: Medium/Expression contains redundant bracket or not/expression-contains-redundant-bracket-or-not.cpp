class Solution {
  public:
    bool checkRedundancy(string &s) {
        // code here
        
        int n= s.size();
        stack<char> st;
        for(int i=0; i<n; i++){
            char ch= s[i];
            if(ch=='(' || ch=='+' || ch=='-' || ch=='/' || ch=='*'){
                st.push(ch);
            }
            else{
                bool flag=true;
                if(ch==')'){
                    while(st.top()!= '('){
                        if(st.top()=='+' || st.top()=='-' || 
                        st.top()=='*' || st.top()=='/'){
                            flag=false;
                        }
                        st.pop();
                    }
                    st.pop();
                    if(flag==true){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
