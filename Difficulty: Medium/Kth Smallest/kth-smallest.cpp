// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        //TC: O(NLOGK), SC: O(K)- pq is holding atmost k elments at once
        priority_queue<int> pq;
        for(int i=0; i<arr.size(); i++){
            pq.push(arr[i]);    
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
    }
};