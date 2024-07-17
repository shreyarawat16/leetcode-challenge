//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToInfix(string pre_exp) {
        // Write your code here
        stack<string> st;
    
        for(int i=pre_exp.size()-1; i>=0; i--){
           string temp="";
           temp+= pre_exp[i];
           if(isalpha(temp[0])){
               st.push(temp);
           }
           else{
               string left= st.top(); st.pop();
               string right= st.top(); st.pop();
               string a="";
              a+= "("+ left+ temp+ right+")";
              st.push(a);
           }
           
    }
    return st.top();
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends