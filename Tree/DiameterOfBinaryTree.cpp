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
        if(!root) return 0;
        int heightOfLeftSubTree = height(root->left);
        int heightOfRightSubTree = height(root->right);
        int maxHeight = max(heightOfLeftSubTree,heightOfRightSubTree)+1;
        return maxHeight;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        //diameter lie in left sub tree
        int diameterInLeftSubTree = diameterOfBinaryTree(root->left);
        //diameter lie in right sub tree
        int diameterInRightSubTree = diameterOfBinaryTree(root->right);
        //diameter in both
        int diameterInBothSide = height(root->left)+height(root->right);
        int diameter = max(diameterInLeftSubTree,max(diameterInRightSubTree,diameterInBothSide));
        return diameter;
    }
};