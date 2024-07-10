//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
void solve(string s, int i, vector<string>& ans, string str){
    if(i>= s.size()){
        ans.push_back(str);
        return;
    }
    
    //without space
   
    solve(s, i+1, ans, str+s[i]);
    //with space
    if(i!= s.size()-1)
    solve(s, i+1, ans, str+s[i]+' ');
}
    vector<string> permutation(string s) {
        // Code Here
        vector<string> ans;
        string str="";
        int i=0;
        solve(s, i, ans, str);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for (int i = 0; i < ans.size(); i++) {
            cout << "(" << ans[i] << ")";
        }
        cout << endl;
    }
}

// } Driver Code Ends