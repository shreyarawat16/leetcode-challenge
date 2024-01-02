//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        vector<int> v;
        int r=-1, m=-1;
        int hasharr[n+1]={0};
        for(int i=0; i<arr.size(); i++){
            hasharr[arr[i]]++;
        }
        for(int i=1; i<=n; i++){
            if(hasharr[i]==2){
                r=i;
            }
            else if(hasharr[i]==0){
            m=i;
            }
        }
        v.push_back(r);
        v.push_back(m);
        return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends