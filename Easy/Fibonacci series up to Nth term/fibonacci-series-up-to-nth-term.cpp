//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Series(int n) {
        // Code here
        int mod= 1e9+7;
        vector<int> ans;
        int a=0;
        int b=1;
        ans.push_back(a);
        ans.push_back(b);
        for(int i=2; i<=n; i++){
            int c= (a+b)%mod;
            ans.push_back(c);
            a=b;
            b=c;
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends