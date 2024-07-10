//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
void solve(int one, int zero, int n, vector<string>& ans, string str, int ind){
    if(ind==n){
        ans.push_back(str);
        return;
    }
   
   if(one == zero){
   solve(one+1, zero, n, ans, str+'1', ind+1);
  
   }
   else if(one>0 && one > zero){
       
       solve(one+1, zero, n, ans, str+'1', ind+1);
       
       solve(one, zero+1, n, ans, str+'0', ind+1);
       
   }
}
	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    vector<string> ans;
	    string str="";
	    int one=0, zero=0, i=0;
	    solve(one, zero, n, ans, str, i);
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends