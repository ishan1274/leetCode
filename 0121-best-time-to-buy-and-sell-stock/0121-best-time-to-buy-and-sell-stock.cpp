class Solution {
public:
    int maxProfit(vector<int>& prices) {
                if (prices.empty()) return 0;

        int buy = prices[0];  // Initialize buy with the first day's price
        int profit = 0;       // Initialize profit to 0
        
        // Iterate through the prices starting from the second day
        for (int i = 1; i < prices.size(); i++) {
            // Update the minimum buy price if the current price is lower
            buy = min(buy, prices[i]);
            
            // Calculate the profit if selling at the current price, and update max profit if it's higher
            profit = max(profit, prices[i] - buy);
        }
        
        // Return the maximum profit found
        return profit;
    }
};