//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
  
    int countSubstrAtMostK(string& s, int k) {
        // code here.
        int n= s.size();
        int count=0,j=0;
        unordered_map<char, int> mp;
        for(int i=0; i<n; i++){
            mp[s[i]]++;
    
                while(mp.size()>k){
                mp[s[j]]--;
                if(mp[s[j]]==0){
                    mp.erase(s[j]);
                }
                 j++;
                }
        
        count+= (i-j+1);
        }
        return count;
       
    }
    int countSubstr(string& s, int k){
        return countSubstrAtMostK(s,k)- countSubstrAtMostK(s,k-1);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.countSubstr(s, k) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends