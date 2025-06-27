class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int maxi=arr[0], secondmaxi=-1;
        int n= arr.size();
        for(int i=1; i<n; i++){
            if(arr[i]> maxi){
                secondmaxi=maxi;
                maxi= arr[i];
            }
            else if(arr[i]<maxi && arr[i]> secondmaxi) {
                secondmaxi= arr[i];
            }
            
        }
        return secondmaxi;
    }
};