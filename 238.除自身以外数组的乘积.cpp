/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);

        int k = 1;
        for (int i = 0; i < nums.size(); ++i) {
            res[i] = k;
            k = k * nums[i];
        }

        k = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            res[i] = res[i] * k;
            k = k * nums[i];
        }

        return res;
    }
};
// @lc code=end

