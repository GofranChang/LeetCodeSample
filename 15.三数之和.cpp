/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return {};

        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i - 1] == nums[i]) continue;

            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum > 0) {
                    --r;
                    while (l < r && nums[r] == nums[r + 1]) --r;
                } else if (sum < 0) {
                    ++l;
                    while (l < r && nums[l - 1] == nums[l]) ++l;
                } else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    --r;
                    while (l < r && nums[r] == nums[r + 1]) --r;
                    ++l;
                    while (l < r && nums[l - 1] == nums[l]) ++l;
                }
            }
        }

        return res;
    }
};
// @lc code=end

