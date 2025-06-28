string sort(string s) {
    vector<int> v(26,0);
    // complete the function here
    int n= s.size();
    for(int i=0; i<n; i++){
        int index= s[i]-'a';
        v[index]++;
    }
    string ans;
    for(int i=0; i<26;i++){
       char ch= i+'a';
       while(v[i]){
         ans+= ch;
         v[i]--;
       }
    }
   return ans;
}