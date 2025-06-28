// User function template for C++

class Solution {
  public:
    // Function to return list containing first n fibonacci numbers.
    vector<int> fibonacciNumbers(int n) {
        // code here
        vector<int> arr(n,0);
        arr[1]=1;
        for(int i=2; i<n; i++){
            arr[i]= arr[i-1]+ arr[i-2];
        }
        return arr;
    }
};