/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    // int maxSubArray(vector<int>& nums) {
    //     vector<int> dp = nums;
    //     int res = dp[0];

    //     for (int i = 1; i < nums.size(); ++i) {
    //         dp[i] = max(nums[i], nums[i] + dp[i - 1]);
    //         res = max(res, dp[i]);
    //     }

    //     return res;
    // }

    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int last = nums[0], res = last;

        for (int i = 1; i < nums.size(); ++i) {
            int cur = max(nums[i], last + nums[i]);
            res = max(res, cur);
            last = cur;
        }

        return res;
    }
};
// @lc code=end

