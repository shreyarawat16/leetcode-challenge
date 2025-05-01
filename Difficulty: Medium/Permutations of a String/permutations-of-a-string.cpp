//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  void solve(string str, int i, set<string>& st){
      if(i== str.size()){
          st.insert(str);
          return;
      }
      for(int j=i; j<str.size(); j++){
          swap(str[j], str[i]);
          solve(str, i+1, st);
          swap(str[j], str[i]);
      }
  }
    vector<string> findPermutation(string &s) {
        // Code here there
        vector<string> ans;
        set<string> st;
       
        solve(s, 0, st);
        
        for(auto it:st){
            ans.push_back(it);
        }
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
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends