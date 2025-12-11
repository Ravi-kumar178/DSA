/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == 0) return 0;
        if(root->val == p->val) return p;
        if(root->val == q->val) return q;

        TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);

        if(leftAns == 0 && rightAns == 0) return 0;
        else if(leftAns != 0 && rightAns == 0) return leftAns;
        else if(leftAns == 0 && rightAns != 0) return rightAns;
        else 
            return root;
    }
};