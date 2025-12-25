class Solution {
public:
    void solve(TreeNode* root, int& ans){
        if(!root) return;

        ++ans;
        solve(root->left,ans);
        solve(root->right,ans);
    };

    int countNodes(TreeNode* root) {
        int ans = 0;
        solve(root,ans);
        return ans;
    }
};