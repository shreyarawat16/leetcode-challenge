class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
       
        int n= words.size();
        vector<vector<int>> adj(26);
        vector<int> indegree(26,0);
        vector<bool> present(26, false);
        for(auto& w: words){
            for(auto ch: w){
                present[ch-'a']= true;
            }
        }
        for(int i=0; i< n-1; i++){
            string s1= words[i];
            string s2= words[i+1];
            int p= s1.size(), q= s2.size();
            int l= min(p,q);
           bool flag= false;
          for(int j=0; j< l; j++){
              if(s1[j]!= s2[j]){
                
                  int u= s1[j]-'a';
                  int v= s2[j]-'a';
                 
                    adj[u].push_back(v);
                    indegree[v]++;
                    flag= true;
                    break;
              }      
          }
           if(!flag && p> q){
              return "";
          }
        }
        queue<int> q;
        for(int i=0; i< 26; i++){
            if(present[i] && indegree[i]==0){
                q.push(i);
            }
        }
        string topo="";
        set<char> st;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            topo+= node+ 'a';
            st.insert(node+'a');
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        
        
       for(int i=0; i<26; i++){
           if(present[i] && indegree[i]!=0){
               return "";
           }
           else if(present[i] && st.find(i+'a')== st.end()){
               topo+= i+'a';
           }
       }
     
       return topo;
    }
};