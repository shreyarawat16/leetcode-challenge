//{ Driver Code Starts
#include <stdio.h>

int addition(int A,int B);


// } Driver Code Ends
//User function Template for C
int addition(int A,int B){
    return A+B;
}

//{ Driver Code Starts.


int main() 
{ 
    int t;
    scanf("%d",&t);
    while(t>0)
    {
        int A, B;
        scanf("%d",&A);
        scanf("%d",&B);
        printf("%d\n",addition(A,B));
        t--;
    }
    return 0; 
} 

// } Driver Code Ends