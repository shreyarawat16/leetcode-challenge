//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  void f(vector<int>& arr, int si, int ei){
      if(si>=ei){
          return;
      }
      int temp= arr[si];
      arr[si]= arr[ei];
      arr[ei]= temp;
      f(arr, si+1, ei-1);
  }
    void reverseArray(vector<int> &arr) {
        // code here
        int si=0, ei= arr.size()-1;
        return f(arr, si, ei);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        ob.reverseArray(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends