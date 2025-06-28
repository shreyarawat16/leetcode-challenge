class Solution {
  public:
    int removeDuplicates(vector<int> &arr) {
        // code here
       //BRUTE - SET DATA STRUCTURE
       set<int> st;
       for(int i=0; i<arr.size(); i++){
           st.insert(arr[i]);
       }
       int ind=0;
       for(auto it: st){
           arr[ind++]= it;
       }
       return ind;
    }
};