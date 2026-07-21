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
    bool pathSum(TreeNode* root, int targetSum, int sum){
        if(root == nullptr) return false;
        
        sum += root->val;

        if(!root->left && !root->right){
            if(targetSum == sum) return true;
            else return false;
        }

        bool leftSub = pathSum(root->left,targetSum,sum);
        bool rightSub = pathSum(root->right,targetSum,sum);

        return leftSub || rightSub;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
       bool ans = pathSum(root,targetSum,0);
       return ans;
    }
};