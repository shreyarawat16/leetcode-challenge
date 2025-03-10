//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
void merge(vector<int>& arr, int si, int ei, int mid){
      
      vector<int> temp;
      
      int i=si, j= mid+1;
      while(i<=mid && j<=ei){
          if(arr[i]<= arr[j]){
              temp.push_back(arr[i]);
              i++;
          }
          else{
             temp.push_back(arr[j]);
             j++;
          }
        }
        while(i<=mid){
            temp.push_back(arr[i]);
            i++;
        }
        while(j<=ei){
            temp.push_back(arr[j]);
            j++;
        }
        int k=0;
        for(int l=si; l<=ei; l++){
            arr[l]= temp[k++];
        }
      }
  
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        if(l>=r) return;
        int mid= l + (r-l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, r, mid);
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        obj.mergeSort(arr, 0, arr.size() - 1);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends