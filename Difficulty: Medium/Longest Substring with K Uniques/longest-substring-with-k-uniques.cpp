class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        //BRUTE
        int n= s.size(), maxi=-1;
        // for(int i=0; i<n; i++){
        //     set<char> st;
        //     for(int j=i; j<n; j++){
        //          st.insert(s[j]);
        //          if(st.size()==k){
        //              maxi= max(maxi, j-i+1);
        //          }
        //          else if(st.size()>k) {
        //              break;
        //          }
        //     }
        // }
        // return maxi;
        
        //SLIDING WINDOW
        int l=0, r=0;
        unordered_map<char, int> mp;
        while(r<n){
            mp[s[r]]++;
            while(mp.size() > k){
                mp[s[l]]--;
                if(mp[s[l]]==0){
                    mp.erase(s[l]);
                }
                l++;
            }
            if(mp.size()==k){
            maxi= max(maxi, r-l+1);
            }
            r++;
        }
        return maxi;
    }
};