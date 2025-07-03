class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        // int n= arr.size(), maxi= 0;
       
        // for(int i=0; i<n; i++){
        //      set<int> st;
        //     for(int j=i; j<n; j++){
        //         st.insert(arr[j]);
        //         if(st.size()<=2){
        //             maxi= max(maxi, j-i+1);
        //         }
        //         else{
        //             break;
        //         }
        //     }
        // }
        // return maxi;
        
        //SLIDING WINDOW
        int l=0, r=0, maxi=0, n= arr.size();
        unordered_map<int,int> mp;
        while(r<n){
            mp[arr[r]]++;
           
        
             while(mp.size()>2){
                mp[arr[l]]--;
                if(mp[arr[l]]==0){
                    mp.erase(arr[l]);
                }
                l++;
               }
               maxi= max(maxi, r-l+1);
            
            r++;
        }
        return maxi;
    }
};