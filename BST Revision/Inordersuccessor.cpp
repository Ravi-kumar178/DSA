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

    void helper(TreeNode* root, TreeNode* target, TreeNode* &succ){
        if(!root) return;

        helper(root->right,target,succ);

        if(root->val == target->val){
            ans = succ;
            return;
        }
        succ = root;

        helper(root->left,target,succ);
        return;
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* target) {
       TreeNode* succ = nullptr;
       helper(root,target,succ);

       return ans;
    }
};