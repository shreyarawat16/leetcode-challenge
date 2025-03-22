//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
 //TC: O(NLOGN) SC: O(N) for temp array
 //Also tell that we are distorting the array
  int mergeSort(vector<int>& nums, int si, int ei, int mid){
      int i=si, j= mid+1, cnt=0;
      vector<int> temp;
      while(i<=mid && j<=ei){
          if(nums[i]> nums[j]){
              
              cnt+= (mid-i+1);
              temp.push_back(nums[j]);
              j++;
          }
          else{
              temp.push_back(nums[i]);
              i++;
          }
      }
      while(i<=mid){
          temp.push_back(nums[i]);
          i++;
      }
      while(j<=ei){
          temp.push_back(nums[j]);
          j++;
      }
      for(int i= si; i<=ei; i++){
          nums[i]= temp[i-si];
      }
      return cnt;
  }
  int merge(vector<int>& arr, int si, int ei){
      int cnt=0;
      if(si>= ei){
          return cnt;
      }
      
      int mid= (si+ei)/2;
      cnt+=merge(arr, si, mid);
      cnt+=merge(arr, mid+1, ei);
      cnt+= mergeSort(arr, si, ei, mid);
      return cnt;
  }
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        //BETTER you can reduce TC to NlogN
        int n= arr.size();
        int start=0, end= n-1;
        return merge(arr, start, end);
        
        //BRUTE TC: O(N*N), SC:O(1) not using any extra space
        // int n= arr.size(), cnt=0;
        // for(int i=0; i<n-1; i++){
        //     int ele= arr[i];
        //     for(int j=i+1; j<n; j++){
                
                 
        //              if(ele> arr[j]) cnt++;
                 
        //     }
        // }
        // return cnt;
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends