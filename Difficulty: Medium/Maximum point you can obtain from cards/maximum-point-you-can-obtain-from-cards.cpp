class Solution {
  public:
    int maxScore(vector<int>& cardPoints, int k) {
        // code here.
        //Brute
        int sum=0;
        for(int i=0; i<k; i++){
            sum+= cardPoints[i];
        }
        int maxi=0;
        maxi= max(maxi,sum);
        int i=k-1;
        int j=cardPoints.size()-1;
        while(i>=0){
        sum-= cardPoints[i];
        sum+= cardPoints[j];
        maxi= max(maxi, sum);
        i--;
        j--;
        }
        return maxi;
    }
};
