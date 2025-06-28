class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int profit= 0, buy_price=prices[0];
        int n= prices.size();
     
        for(int i=1; i<n; i++){
            if(prices[i]< buy_price){
                buy_price= prices[i];
        
            }
            else{
               profit= max(profit, prices[i]- buy_price);
            }
           
        }
        return profit;
    }
};
