//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
         stack<int> st;
         for(int i=n-1; i>=0; i--){
             st.push(i);
         }
         while(st.size()>1){
             int x= st.top(); st.pop();
             int y= st.top(); st.pop();
             if(M[x][y] && !M[y][x]){
                 st.push(y);
             }
             else if(M[y][x] && !M[x][y]){
                 st.push(x);
             }
         }
         if(st.empty()) return -1;
         int num= st.top();
         int row=0, col=0;
         for(int i=0; i<n; i++){
             row+= M[num][i];
             col+= M[i][num];
             
         }
         if(row==0 && col==n-1){
             return num;
         }
         return -1;
    }
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
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends