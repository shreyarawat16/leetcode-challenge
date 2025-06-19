// function Template for C++

class Solution {
  public:
    queue<int> reverseQueue(queue<int> &q) {
        // code here.
        queue<int> qans;
        stack<int> st;
        while(!q.empty()){
            st.push(q.front());
            q.pop();
        }
        while(!st.empty()){
            int ele= st.top();
            st.pop();
            qans.push(ele);
        }
        return qans;
    }
};