class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int price = 0;

        for(int i = 1 ; i< prices.size(); i++){
            if(prices[i] > prices[i-1])
                price += prices[i] - prices[i-1];
        }

        return price;
    }
};