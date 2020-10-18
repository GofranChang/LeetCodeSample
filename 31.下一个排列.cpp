/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.empty()) return;

        int pos = nums.size() - 1;
        while (pos > 0 && nums[pos] <= nums[pos - 1]) --pos;
        reverse(nums.begin() + pos, nums.end());

        if (pos > 0) {
            for (int start = pos; pos < nums.size(); ++start) {
                if (nums[start] > nums[pos - 1]) {
                    swap(nums[start], nums[pos - 1]);
                    return;
                }
            }
        }
    }
};
// @lc code=end

