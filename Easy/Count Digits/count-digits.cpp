//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int evenlyDivides(int N){
      
        int temp=N,count =0;
        while(temp>0)
        {
           int  LASTDIGIT=temp%10;
            //count++;
            if(LASTDIGIT>0&&N%LASTDIGIT==0)
            {
                count++;
            }
            temp=temp/10;
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.evenlyDivides(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends