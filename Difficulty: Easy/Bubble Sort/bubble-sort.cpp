class Solution {
  public:
    void bubbleSort(vector<int>& arr) {
        // code here
        int n= arr.size();
        for(int i=0; i<n-1; i++){
            for(int j=0;  j<n-1-i; j++){
                if(arr[j]> arr[j+1]){
                    swap(arr[j], arr[j+1]);
                }
                
            }
        }
        
    }
};