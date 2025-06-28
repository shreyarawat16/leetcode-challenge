// User template code in C++

class Solution {
  public:
  
bool ispalin(string s){
    int i=0, j=s.size()-1;
    while(i<=j){
        if(s[i]!= s[j]){
            return false;
        }
        i++; j--;
    }
    return true;
}
    bool sentencePalindrome(string &s) {
        // code here
        int n= s.size();
        string str="";
        for(int i=0; i<n; i++){
           
         if(isalnum(s[i])){
             str+= tolower(s[i]);
         }
          
        }
        return ispalin(str);
            
        
    }
};