/* You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0. */

// Runtime: 96 ms, faster than 98.10% of C++ online submissions for Best Time to Buy and Sell Stock.
// Memory Usage: 93.3 MB, less than 91.08% of C++ online submissions for Best Time to Buy and Sell Stock.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        min_p = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            min_p = prices[i] < min_p ? prices[i] : min_p;
            ans = prices[i] - min_p > ans ? prices[i] - min_p : ans;
        }
        return ans;
    }
    
private:
    int min_p;
    int ans = 0;
};
