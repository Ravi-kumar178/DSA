/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
};
*/

class Solution {
  public:
    pair<int, int> helper(TreeNode *root) {
        if (!root)
            return {0, 0};

        auto left = helper(root->left);
        auto right = helper(root->right);

        // include node
        int a = root->val + left.second + right.second;
        // exclude node
        int b = max(left.first, left.second) + max(right.first, right.second);

        return {a, b};
    }
    int getMaxSum(TreeNode *root) {
        // Placeholder for actual logic to compute max sum of non-adjacent nodes
        auto ans = helper(root);
        return max(ans.first, ans.second);
    }
};