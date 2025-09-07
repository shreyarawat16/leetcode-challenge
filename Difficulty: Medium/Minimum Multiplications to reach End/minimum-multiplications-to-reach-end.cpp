// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
          int mod= 100000;
          int n= arr.size();
          queue<int> q;
          vector<int> dist(mod,1e9);
          dist[start]=0;
          q.push(start);
          while(!q.empty()){
             
           int node= q.front();
           if(node== end){
               return dist[node];
           }
           q.pop();
           for(auto it: arr){
               int newNode= (1LL* node*it)%mod;
               if(1+ dist[node]< dist[newNode]){
                   dist[newNode]= 1+dist[node];
                   q.push(newNode);
               }
           }
           }
           return -1;
    }
};
