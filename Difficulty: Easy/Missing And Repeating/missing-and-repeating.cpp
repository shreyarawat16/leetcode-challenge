//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        //BETTER
        int n= arr.size();
        int hashArr[n+1]={0};
        int repeating=-1, missing=-1;
        for(int i=0; i<n; i++){
            hashArr[arr[i]]++;
        }
        for(int i=1; i<=n; i++){
            if(hashArr[i]==2){
                repeating=i;
            }
            else if(hashArr[i]==0){
                missing= i;
            }
            if(repeating!=-1 && missing!=-1) break;
        }
        return {repeating, missing};
        //BRUTE TC: O(N*N) SC:O(1)
        //  vector<int> ans;
        //  int n= arr.size();
        //  int cnt=0, repeating=-1, missing=-1;
        //  for(int i=1; i<=n; i++){
        //      for(int j=0; j<n; j++){
        //          if(arr[j]==i){
        //              cnt++;
                     
        //          }
        //      }
        //          if(cnt==2){
        //              repeating=i;
        //          }
        //          else if(cnt==0){
        //              missing=i;
        //          }
        //          if(repeating!=-1 && missing!=-1){
        //              break;
        //          }
        //       }
        // return {repeating, missing};
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends