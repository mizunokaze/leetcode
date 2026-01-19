class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cost = INT_MAX, profit = 0;
        for(int p : prices){
            cost = min(cost, p);
            profit = max(profit, p - cost);
        }
        return profit;
    }
};
