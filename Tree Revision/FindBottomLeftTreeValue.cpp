/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode* root, int level, int& maxVisitedLevel, int& ans){
        if(!root) return;

        if(level > maxVisitedLevel){
            maxVisitedLevel = level;
            ans = root->val;
        }

        helper(root->left, level+1, maxVisitedLevel, ans);
        helper(root->right, level+1, maxVisitedLevel, ans);
        return;
    }
    int findBottomLeftValue(TreeNode* root) {
        int maxVisitedLevel = 0;
        int ans = root->val;
        int level = 1;
        helper(root,level,maxVisitedLevel, ans);
        return ans;
    }
};