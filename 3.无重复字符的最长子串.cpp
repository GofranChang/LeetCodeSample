/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) return s.size();

        vector<int> m(128, -1);
        int left = -1, len = 0;
        for (int i = 0; i < s.size(); ++i) {
            left = max(left, m[s[i]]);
            len = max(len, i - left);
            m[s[i]] = i;
        }

        return len;
    }
};
// @lc code=end

