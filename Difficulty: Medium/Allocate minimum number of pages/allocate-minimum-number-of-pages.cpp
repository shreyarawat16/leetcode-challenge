//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
  bool isvalid(int arr[], int n , int k, int maxpages){
      int sum1=0, cnt=1;
      for(int i=0; i<n; i++){
          sum1+= arr[i];
          if(sum1 > maxpages){
              cnt++;
              sum1= arr[i];
          }
      }
      return cnt<= k ;
  }
    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m) {
        // code here
        long long res=-1;
        if(n<m){
            return res;
        }
        int start=-1, end=0;
        for(int i=0; i<n; i++){
            end+= arr[i];
            start= max(start, arr[i]);
        }
        while(start<=end){
            int mid= start+(end-start)/2;
            if(isvalid(arr, n, m, mid)== true){
                res= mid;
                end= mid-1;
            }
            else{
                start= mid+1;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends