class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i=0; i<a.size(); i++){
            if(mp.find(a[i])== mp.end()){
                mp[a[i]]++;
                ans.push_back(a[i]);
            }
        }
        for(int i=0; i<b.size(); i++){
            if(mp.find(b[i])== mp.end()){
                mp[b[i]]++;
                ans.push_back(b[i]);
            }
        }
        return ans;
    }
};