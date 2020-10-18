/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        vector<int> m(128, 0);
        for (auto c : t) ++m[c];

        int curLeft = 0, curSize = 0;
        int resLeft = 0, resSize = s.size() + 1;

        for (int i = 0; i < s.size(); ++i) {
            if (--m[s[i]] >= 0) ++curSize;

            while (curSize == t.size()) {
                if (resSize > i - curLeft + 1) {
                    resSize = i - curLeft + 1;
                    resLeft = curLeft;
                }

                if (++m[s[curLeft]] > 0) --curSize;
                ++curLeft;
            }
        }

        return (resSize == s.size() + 1) ? "" : s.substr(resLeft, resSize);
    }
};
// @lc code=end

