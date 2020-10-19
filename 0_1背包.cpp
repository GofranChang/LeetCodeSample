/*
 * @lc app=leetcode.cn id=null lang=cpp
 *
 * [附加] 0-1背包问题
 */

int knapsack(int W, int N, vector<int>& wt, vector<int>& val) {
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= N; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (w < wt[i - 1]) {
                dp[i][w] = dp[i - 1][w];
            } else {
                dp[i][w] = max(dp[i - 1][w - wt[i - 1]] + val[i - 1], \
                               dp[i - 1][w]);
            }
        }
    }

    return dp[N][W];
}