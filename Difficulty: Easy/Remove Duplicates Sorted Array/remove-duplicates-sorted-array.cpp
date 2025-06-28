class Solution {
  public:
    int removeDuplicates(vector<int> &arr) {
        // code here
        int n= arr.size();
        vector<int> ans;
        
        int k=0; //first unique location
       
        for(int i=1; i<n; i++){
            if(arr[i] != arr[k]){
                k++;
                arr[k]= arr[i];
            }
          
        }
       return k+1;
    }
};