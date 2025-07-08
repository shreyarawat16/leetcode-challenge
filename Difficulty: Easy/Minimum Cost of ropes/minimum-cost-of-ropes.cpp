class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        int cost=0;
        int n= arr.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<n; i++){
            pq.push(arr[i]);
            
        }
        while(pq.size()!=1){
           
            int x=pq.top();
            pq.pop();
           
          
              int y= pq.top();
               pq.pop();
            
            int sum= x+y;
            cost+= sum;
            pq.push(sum);
        }
        
        return cost;
    }
};