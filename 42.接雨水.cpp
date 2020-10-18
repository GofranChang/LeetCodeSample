/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 1) return 0;

        stack<int> st;
        int res = 0;
        for (int i = 0; i < height.size(); ++i) {
            while (!st.empty() && height[i] >= height[st.top()]) {
                int cur = st.top();
                st.pop();
                if (st.empty()) break;

                int l = st.top();
                int r = i;
                int h = min(height[l], height[r]) - height[cur];
                res += (r - l - 1) * h;
            }

            st.push(i);
        }

        return res;
    }
};
// @lc code=end

