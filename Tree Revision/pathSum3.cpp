/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
  public:
    void helper(TreeNode *root, int targetSum, long long currSum,
                unordered_map<long long, int> prefixSum, int &path) {
        if (!root)
            return;

        currSum += root->val;

        if (prefixSum.find(currSum - targetSum) != prefixSum.end()) {
            path += prefixSum[currSum - targetSum];
        }

        prefixSum[currSum]++;

        helper(root->left, targetSum, currSum, prefixSum, path);
        helper(root->right, targetSum, currSum, prefixSum, path);

        prefixSum[currSum]--;
        return;
    }
    int pathSum(TreeNode *root, int targetSum) {
        unordered_map<long long, int> prefixSum;
        int path = 0;
        prefixSum[0] = 1;
        long long currSum = 0;
        helper(root, targetSum, currSum, prefixSum, path);
        return path;
    }
};