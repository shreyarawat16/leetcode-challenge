//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
bool isprime(int n){
    
    for(long long i=2; i<= sqrt(n); i++){
        if(n%i ==0){
            return false;
        }
    }
    return true;
}
    long long int largestPrimeFactor(int N){
        // code here
        if( isprime(N)){
            return N;
        }
        long long int maxi= -1;
        long long int i;
        for( i=2; i<= sqrt(N) ; i++){
            if(N%i==0){
                long long int k= N/i;
               if( isprime(i)== true){
                   maxi= max(maxi, i);
               }
               if( isprime(k)){
                   maxi= max(maxi, k);
               }
            }
            
        }
        
        return maxi;
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
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends