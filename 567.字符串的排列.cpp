/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> m1(128, 0), m2(128, 0);
        for (auto c : s1) ++m1[c];

        for (int i = 0; i < s1.size(); ++i) ++m2[s2[i]];

        for (int l = 0, r = s1.size(); r < s2.size(); ++l, ++r) {
            if (m1 == m2) return true;

            --m2[s2[l]];
            ++m2[s2[r]];
        }

        return (m1 == m2);
    }
};
// @lc code=end

