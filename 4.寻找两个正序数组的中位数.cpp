/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m > n) return findMedianSortedArrays(nums2, nums1);

        int LMax1, RMin1, LMax2, RMin2, c1, c2, lo = 0, hi = m;
        while (lo <= hi) {
            c1 = (lo + hi) / 2;
            c2 = (m + n) / 2 - c1;

            LMax1 = (c1 == 0) ? INT_MIN : nums1[c1 - 1];
            RMin1 = (c1 == m) ? INT_MAX : nums1[c1];
            LMax2 = (c2 == 0) ? INT_MIN : nums2[c2 - 1];
            RMin2 = (c2 == n) ? INT_MAX : nums2[c2];

            if (LMax1 > RMin2)
                hi = c1 - 1;
            else if (LMax2 > RMin1)
                lo = c1 + 1;
            else
                break;
        }

        return (0 == (m + n) % 2) ? ((max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0) : min(RMin1, RMin2);
    }
};
// @lc code=end

