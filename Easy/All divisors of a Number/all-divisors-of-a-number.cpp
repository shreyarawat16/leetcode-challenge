//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void print_divisors(int n) {
        
        vector<int> s;
        for(int i=1; i<= sqrt(n) ; i++){
            if(n%i==0){
               s.push_back(i);
               if (n/i!=i){
                    s.push_back(n/i);
                }
            }
            
        }
        sort(s.begin(),s.end());
        for (int val:s){
            cout<<val<<" ";
        }
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Solution ob;
        ob.print_divisors(n);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends