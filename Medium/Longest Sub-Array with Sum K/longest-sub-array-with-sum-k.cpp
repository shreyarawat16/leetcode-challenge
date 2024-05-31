//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
       unordered_map<int, int> mp;
       int maxi;
       int sum=0;
       for(int i=0; i<N; i++){
           sum+= A[i];
           if(sum==K ){
               maxi= max(maxi, i+1);
           }
           int newtarget= sum-K;
           if(mp.find(newtarget)!= mp.end()){
               maxi= max(maxi, i- mp[newtarget]);
           }
       //If the array contains 0.
       //If the sum already exists then donot reupdate it
       if(mp.find(sum)== mp.end()){
               mp[sum]=i;
           }
    } 
    return maxi;
    }

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends