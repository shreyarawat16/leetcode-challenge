class Solution {
  public:
  long long solve(long long A[], long long k, long long N){
      priority_queue<int> pq;
      for(int i=0; i<N; i++){
          pq.push(A[i]);
          if(pq.size()>k){
              pq.pop();
          }
         
      }
      return pq.top();
  }
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2) {
        // Your code goes here
        int sum=0;
        
        long long first=solve(A,K1,N);
        long long second=solve(A,K2,N);
        for(long long i=0; i<N; i++){
            if(A[i]> first && A[i]< second){
                sum+= A[i];
            }
        }
        return sum;
    }
};