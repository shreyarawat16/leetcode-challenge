class Solution {
  public:
    int countMinReversals(string s) {
        // code here
        stack<char> st;
        int n= s.size();
        if(n%2==1){
            return -1;
        }
        for(int i=0; i<n; i++){
            char ch= s[i];
            if(ch=='{'){
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
        int a=0,b=0;
        while(!st.empty()){
            if(st.top()=='{'){
                a++;
                st.pop();
            }
            else{
                b++;
                st.pop();
            }
        }
        int ans=(a+1)/2+ (b+1)/2;
        return ans;
    }
};