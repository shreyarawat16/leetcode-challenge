//{ Driver Code Starts
// Initial Template for C

#include <stdio.h>


// } Driver Code Ends

// User function Template for C

int floorSqrt(int n) {
    // Your code goes here
    int ans=1;
    for(int i=1; i<=n; i++){
        if(i*i <= n){
            ans=i;
        }
        else{
            break;
        }
        
    }
    return ans;
}


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%ld", &n);

        printf("%ld\n", floorSqrt(n));
    }
    return 0;
}

// } Driver Code Ends