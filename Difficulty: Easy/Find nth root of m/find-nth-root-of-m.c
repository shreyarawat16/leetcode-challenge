//{ Driver Code Starts
// Initial Template for C
#include <stdio.h>


// } Driver Code Ends

// User function Template for C
int nthRoot(int n, int m) {
    // code here
    for(int i=1; i<=m; i++){
        if(pow(i,n)== m){
            return i;
        }
        else if(pow(i,n)>m){
            break;
        }
    }
    return -1;
}


//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d", &tc); // Read number of test cases

    while (tc--) {
        int n, m;
        scanf("%d %d", &n, &m); // Read n and m

        int ans = nthRoot(n, m); // Call nthRoot to calculate the answer
        printf("%d\n", ans);     // Output the result
        printf("~\n");
    }

    return 0;
}

// } Driver Code Ends