//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        //OPTIMISED APPROACH
        stack<int> st;
        vector<long long> ans(n,-1);
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()]<= arr[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]= arr[st.top()];
            }
            st.push(i);
        }
        return ans;
    }
        //BRUTE FORCE, GIVES TC
    //     vector<long long> ans(n,-1);
    //     int k=0;
    //     for(int i=0; i<n-1; i++){
    //         int j;
    //         for( j=i+1; j<n; j++){
    //             if(arr[j]> arr[i]){
    //                 ans[k++]=arr[j];
    //                 break;
    //             }
    //         }
    //         if(j==n){
    //             k++;
    //         }
    //     }
        
    //     return ans;
    // }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends