//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
int ismaximum(int i, int j, string input){
       
        int maxi=INT_MIN;
        for(int k=i; k<=j; k++){
            if(input[k]-'0' > maxi){
                maxi= input[k]-'0';
            }
    }
    return maxi;
}
    void solve(int ind, string input, string& ans,int k){
        if( k==0 || ind==input.size()){
            return;
        }
       int n= input.size();
    
        for( int j= ind+1; j< input.size(); j++){
            if(input[j]> input[ind] && input[j]-'0'==ismaximum(j, n-1, input)){
                swap(input[ind], input[j]);
                if( input.compare(ans)>0){
                    ans= input;
                }
                solve(ind+1, input, ans, k-1);
                swap(input[ind], input[j]);
        }
      
    }
    solve(ind+1, input, ans, k);
}
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       // code here.
       string ans=str;
       int i=0;
       solve(i, str, ans,k);
       return ans;
       
    }
};

//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends