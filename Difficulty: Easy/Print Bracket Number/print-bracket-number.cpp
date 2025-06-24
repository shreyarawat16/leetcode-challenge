// User function template for C++
class Solution {
  public:

    vector<int> bracketNumbers(string str) {
        // Your code goes here
        vector<int> ans;
       stack<pair<char, int>> st;
       int cnt=0;
       for(int i=0; i<str.size(); i++){
           if(str[i]=='('){
               cnt++;
               ans.push_back(cnt);
               st.push({str[i], cnt});
           }
           else if(str[i]==')'){
               auto it= st.top();
               ans.push_back(it.second);
               st.pop();
           }
       }
       return ans;
    }
};