//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        stack<int> st;
        int n= S.size();
        string ans="";
        
        int num=1;
        for(int i=0; i<=n ; i++){
            st.push(num);
            if(i==n || S[i]=='I'){
                while(!st.empty()){
               ans+= st.top()+'0';
                st.pop();
               
            }
            }
            num++;
            }
    return ans;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends