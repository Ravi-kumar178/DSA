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
    struct NodeInfo{
        bool isBST;
        int minValue;
        int maxValue;
        int sum;
    };

    int maximumSum =0;
    NodeInfo helper(TreeNode* root){

        if(!root){
            return {true,INT_MAX,INT_MIN,0};
        }

        NodeInfo left = helper(root->left);
        NodeInfo right = helper(root->right);

        NodeInfo curr;
        curr.sum = root->val + left.sum + right.sum;

        if(left.isBST && right.isBST && left.maxValue < root->val && right.minValue > root->val){
            curr.isBST = true;
            curr.minValue = min(root->val, left.minValue);
            curr.maxValue = max(root->val, right.maxValue);

            maximumSum = max(curr.sum,maximumSum);
        }
        else{
            curr.isBST = false;
        }
        return curr;
    }
    int maxSumBST(TreeNode* root) {
        helper(root);
        return maximumSum;
    }
};