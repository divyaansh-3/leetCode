class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int j=1;
        int max_profit=0;
        int least= prices[j-1];
        while(j<n){
             least = min(least,prices[j]);
            if(least < prices[j]){
                int profit = prices[j]-least;
                max_profit= max(profit, max_profit);
            }
            j++;
            
        }
        return max_profit;
        
    }
};