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
    vector<vector<int>>ans;

    void solve(TreeNode* root, int targetSum, int sum, vector<int>arr){
        if(!root) return;

        sum += root->val;
        arr.push_back(root->val);

        if(!root->left && !root->right){
            if(sum == targetSum){
                ans.push_back(arr);
                return;
            }
            return;
        }

        solve(root->left,targetSum,sum,arr);
        solve(root->right,targetSum,sum,arr);

        return;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>arr;
        int sum = 0;
        solve(root,targetSum,sum,arr);
        return ans;
    }
};