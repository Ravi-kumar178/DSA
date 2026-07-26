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
    bool helper(TreeNode* root, long long lowerBound, long long upperBound) {
        if (!root)
            return true;

        bool cond1 = (root->val > lowerBound);
        bool cond2 = (root->val < upperBound);

        bool leftAns = helper(root->left, lowerBound, root->val);
        bool rightAns = helper(root->right, root->val, upperBound);

        if (cond1 && cond2 && leftAns && rightAns)
            return true;
        else
            return false;
    }
    bool isValidBST(TreeNode* root) {
        long long lowerBound =  -2147483658;
        long long upperBound = 2147483657;
        bool ans = helper(root, lowerBound, upperBound);
        return ans;
    }
};