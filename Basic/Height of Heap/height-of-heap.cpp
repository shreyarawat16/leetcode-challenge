//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
/*
void heapify(int arr[], int n, int index){
    int smallest= index, l= 2*index+1, r= 2*index+2;
    if(l<n && arr[l]< arr[smallest]){
        smallest= l;
    }
    else if(r<n && arr[r]< arr[smallest]){
        smallest= r;
    }
    if(smallest!= index){
        swap(arr[index], arr[smallest]);
        heapify(arr, n, smallest);
    }
}
void buildminheap(int arr[], int n){
    for(int i=n/2-1; i>=0; i--){
        heapify(arr, n, i);
    }
}*/
    int heapHeight(int N, int arr[]){
        int cnt=0;
         while(N>1){
             N= N/2;
             cnt++;
         }
         return cnt;
    }
};

//{ Driver Code Starts.

int main() { 
    int t;
    cin>>t;
    while(t--){
        int N;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.heapHeight(N, arr) << endl;
    }
    return 0; 
} 

// } Driver Code Ends