class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int l=-1, sl=-1, n=arr.size();
        for(int i=0; i<n; i++){
            if(arr[i]> l){
              
                sl= l;
                l=arr[i];
            }
            else if(arr[i]> sl && arr[i]< l){
                sl=arr[i];
            }
        }
        return sl;
    }
};