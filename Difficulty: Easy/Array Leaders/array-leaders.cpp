//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        //BRUTE TC: O(N*2), SC: O(N) extra space to store the answer
    //     vector<int> ans;
       
    //     int n= arr.size();
        
    //     for(int i=0; i< n-1; i++){
    //     bool flag= true;
    //         for(int j= i+1; j<n; j++){
    //             if(arr[j]> arr[i]){
    //                 flag= false;
    //                 break;
    //             }
    //         }
    //         if(flag== true){
    //             ans.push_back(arr[i]);
    //         }
    //     }
    //  ans.push_back(arr[n-1]);
    //  return ans;
    // }
    
    //OPTIMAL
     vector<int> ans;
     int n= arr.size();
     
    int maxi= INT_MIN;
    
    for(int i=n-1; i>=0; i--){
        if(maxi <= arr[i]){
             ans.push_back(arr[i]);
            maxi= arr[i];
           
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after the integer input
    while (t--) {
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num); // Read the array elements from input string

        Solution obj;
        vector<int> result = obj.leaders(a);

        // Print the result in the required format
        if (result.empty()) {
            cout << "[]"; // Print empty brackets if no leaders are found
        } else {
            for (int i = 0; i < result.size(); i++) {
                if (i != 0)
                    cout << " ";
                cout << result[i];
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends