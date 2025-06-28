class Solution {
  public:
 
    string FirstNonRepeating(string &s) {
        // Code here
      unordered_map<char, int> freq;
      queue<char> q;
      string ans="";
      for(int i=0; i<s.size(); i++){
          char ch= s[i];
          q.push(ch);
          freq[ch]++;
          while(!q.empty() && freq[q.front()]>1){
              q.pop();
          }
          if(!q.empty()){
          ans+= q.front();
          }
          else{
              ans+= '#';
          }
      }
      return ans;
    }
};