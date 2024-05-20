//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            stack<string> st;
            string ans="";
            string temp="";
            for(int i=0; i<s.size(); i++){
                char ch= s[i];
                if(ch== '+' || ch=='-' || ch=='*' || ch=='/'){
                    st.push(temp);
                    temp="";
                    temp+=ch;
                    st.push(temp);
                    temp="";
                }
                else{
                    temp+= s[i];
                    
                    
                }
                
            }
            st.push(temp);
            while(!st.empty()){
                ans+= st.top();
                st.pop();
            }
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends