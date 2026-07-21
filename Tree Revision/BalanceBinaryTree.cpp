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
    int height(TreeNode* root){
        if(root == nullptr) return 0;

        int leftSub = height(root->left);
        int rightSub = height(root->right);

        return max(leftSub,rightSub) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;

        int leftSubHeight = height(root->left);
        int rightSubHeight = height(root->right);
        bool currNodeAns = (abs(leftSubHeight - rightSubHeight) <= 1);

        bool leftNodeAns = isBalanced(root->left);
        bool rightNodeAns = isBalanced(root->right);

        if(currNodeAns && leftNodeAns && rightNodeAns) return true;
        return false;
    }
};