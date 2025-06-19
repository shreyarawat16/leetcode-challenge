class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        // code here
        queue<int> ans;
        stack<int> st;
        int n= q.size();
        if(k>n){
            return q;
        }
        while(k!=0){
            st.push(q.front());
            q.pop();
            k--;
        }
        while(!st.empty()){
            ans.push(st.top());
            st.pop();
        }
        while(!q.empty()){
            ans.push(q.front());
            q.pop();
        }
        return ans;
    }
};