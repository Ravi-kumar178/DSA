/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
*/

class Solution {
public:
    TreeNode* ans = nullptr;
    void helper(TreeNode* root, TreeNode* target, TreeNode* &predecessor){
        if(!root) return;

        helper(root->left,target,predecessor);
        if(root->val == target->val) {
            ans = predecessor;
            return;
        }
        predecessor = root;
        helper(root->right,target,predecessor);

        return;
    }
    int inorderPredecessor(TreeNode* root, TreeNode* target) {
       TreeNode* predecessor = nullptr;
       helper(root,target,predecessor);
       return (ans == nullptr)?-1:ans->val;
    }
};