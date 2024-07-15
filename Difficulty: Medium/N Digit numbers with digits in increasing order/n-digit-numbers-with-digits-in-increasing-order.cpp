//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  void solve(int n, vector<int>& v, vector<int>& ans){
      
      if(n==0){
          int val=0;
         for(int i=0; i<v.size(); i++){
             val= val*10+ v[i];
             
         }
         ans.push_back(val);
         return;
      }
      for(int i=1; i<10; i++){
          
          if( v.size()==0 || i> v[v.size()-1]){
          v.push_back(i);
          solve(n-1, v, ans);
          v.pop_back();
      }
      
     }
  }
    vector<int> increasingNumbers(int n) {
        vector<int> ans;
       if(n==1){
           for(int i=0; i<10; i++){
               ans.push_back(i);
              
           }
           return ans;
       }
       vector<int> v;
    
        solve(n, v, ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> ans = ob.increasingNumbers(N);
        for (auto num : ans) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends