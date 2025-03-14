//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        //BRUTE . USING SET DS
        set<int> st;
        int n= a.size(), m= b.size();
        for(int i=0; i<n; i++){
            st.insert(a[i]);
        }
        for(int j=0; j<m; j++){
            st.insert(b[j]);
        }
        vector<int> ans;
        for(auto it: st){
            ans.push_back(it);
        }
        return ans;
        // int n= a.size(), m= b.size();
        // vector<int> ans;
        // int i=0, j=0;
        // while(i<n && j<m){
        //     if(a[i] == b[j]){
        //         if(ans.empty() || a[i]!= ans.back()){
        //             ans.push_back(a[i]);
        //         }
        //         i++;
        //         j++;
        //     }
        //     else if(a[i] < b[j]){
        //         if(ans.empty() || a[i]!= ans.back()){
        //             ans.push_back(a[i]);
        //         }
        //         i++;
        //     }
        //     else{
        //         if(ans.empty() || b[i]!= ans.back()){
        //             ans.push_back(b[j]);
        //         }
        //         j++;
        //     }
            
        // }
        // while(i<n){
        //     if(ans.empty() || a[i]!= ans.back()){
        //         ans.push_back(a[i]);
        //     }
        //     i++;
        // }
        // while(j<m){
        //      if(ans.empty() || b[i]!= ans.back()){
        //             ans.push_back(b[j]);
        //         }
        //         j++;
        // }
        // return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a, b;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.findUnion(a, b);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends