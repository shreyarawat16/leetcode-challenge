//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        //BRUTE generate all subarrays
    //     int n= arr.size(), ans=INT_MIN;
    //     for(int i=0; i<n; i++){
    //         int sum=0;
    //         for(int j=i; j<n; j++){
    //             sum+= arr[j];
    //             if(sum==k){
    //                 ans= max(ans, j-i+1);
    //             }
    //         }
    //     }
    //     return ans;
    // }
    
    //BETTER-> HASHING
    
        unordered_map<int, int> mp;
        int n= arr.size();
        int sum=0, maxi= 0;
        for(int i=0; i<n; i++){
            sum+= arr[i];
            if(k==sum){
              maxi= max(maxi, i+1);
            }
            if(mp.find(sum-k)!= mp.end()){
                maxi= max(maxi, i-mp[sum-k]);
            }
            if(mp.find(sum)== mp.end()){
                mp[sum]=i;
            }
        }
        return maxi;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends