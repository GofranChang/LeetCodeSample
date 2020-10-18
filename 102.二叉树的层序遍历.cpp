/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (nullptr == root) return {};
        vector<vector<int>> res;

        res.push_back({root->val});
        queue<TreeNode*> q;
        if (root->left) q.push(root->left);
        if (root->right) q.push(root->right);

        vector<int> levelRes;
        TreeNode* tmpNode = nullptr;
        while (!q.empty()) {
            int n = q.size();
            while (n-- > 0) {
                tmpNode = q.front();
                q.pop();
                levelRes.push_back(tmpNode->val);
                if (tmpNode->left) q.push(tmpNode->left);
                if (tmpNode->right) q.push(tmpNode->right);
            }

            res.push_back(levelRes);
            levelRes.clear();
        }

        return res;
    }
};
// @lc code=end

