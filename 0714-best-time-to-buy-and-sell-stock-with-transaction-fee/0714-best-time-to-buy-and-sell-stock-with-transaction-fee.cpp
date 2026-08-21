class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int cash = 0;
        int hold = -prices[0];

        for (int i = 1; i < prices.size(); i++) {
            int oldCash = cash;

            // Sell today
            cash = max(cash, hold + prices[i] - fee);

            // Buy today
            hold = max(hold, oldCash - prices[i]);
        }

        return cash;
    }
};