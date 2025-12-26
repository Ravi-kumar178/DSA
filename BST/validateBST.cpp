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
    bool solve(TreeNode* root, long long lowerBound, long long upperBound){
        if(!root) return true;

        //1 case
        bool cond1 = (root->val > lowerBound);
        bool cond2 = (root->val < upperBound);

        //check left subtree
        bool leftAns = solve(root->left,lowerBound,root->val);
        //check right subtree
        bool rightAns = solve(root->right,root->val,upperBound);
        if(cond1 && cond2 && leftAns && rightAns){
            return true;
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        long long lowerBound = -2147483658;
        long long upperBound = 2147483657;

        bool ans = solve(root,lowerBound,upperBound);
        return ans;
    }
};