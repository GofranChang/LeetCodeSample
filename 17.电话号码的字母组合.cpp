/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    Solution() {
        _mNumberMap['2'] = "abc";
        _mNumberMap['3'] = "def";
        _mNumberMap['4'] = "ghi";
        _mNumberMap['5'] = "jkl";
        _mNumberMap['6'] = "mno";
        _mNumberMap['7'] = "pqrs";
        _mNumberMap['8'] = "tuv";
        _mNumberMap['9'] = "wxyz";
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> res;
        string cur = "";

        backtrace(res, cur, 0, digits);
        return res;
    }

private:
    void backtrace(vector<string>& res, string& cur, int index, const string& digits) {
        if (cur.size() == digits.size()) {
            res.push_back(cur);
            return;
        }

        for (auto c : _mNumberMap[digits[index]]) {
            cur.push_back(c);
            backtrace(res, cur, index + 1, digits);
            cur.pop_back();
        }
    }

private:
    map<char, string> _mNumberMap;
};
// @lc code=end

