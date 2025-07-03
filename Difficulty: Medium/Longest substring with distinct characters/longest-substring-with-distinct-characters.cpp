class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        //BRUTE- find all substrings
        int n= s.size(), maxi=0;
        
        for(int i=0; i<n; i++){
            unordered_map<char, int> mp;
            
            for(int j=i; j<n; j++){
                if(mp.find(s[j])!= mp.end()){
                    break;
                }
                else{
                    mp[s[j]]++;
                    
                    maxi= max(maxi, j-i+1);
                }
            }
        }
        return maxi;
    }
};
