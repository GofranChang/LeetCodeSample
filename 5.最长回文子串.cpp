/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) return s;

        int left = 0, len = 0;
        for (int i = 1; i < s.size(); ++i) {
            int l = i - 1, r = i + 1;

            while (l >= 0 && s[l] == s[i]) --l;
            while (r < s.size() && s[r] == s[i]) ++r;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                --l;
                ++r;
            }

            if (r - l - 1 > len) {
                left = l;
                len = r - l - 1;
            }
        }

        return string(s, left + 1, len);
    }
};
// @lc code=end

