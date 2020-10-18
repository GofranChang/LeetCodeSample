/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lastRes_0 = 0, lastRes_1 = INT_MIN;

        for (int i = 0; i < prices.size(); ++i) {
            lastRes_0 = max(lastRes_0, lastRes_1 + prices[i]);
            lastRes_1 = max(lastRes_1, -prices[i]);
        }

        return lastRes_0;
    }
};
// @lc code=end

