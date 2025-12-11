class Solution {
public:
    void solve(TreeNode* root, int targetSum, int sum, vector<int>temp, vector<vector<int>> &ans){
        //base case
        if(root == 0){
            return;
        }
        sum += root->val;
        temp.push_back(root->val);
        if(root->left == 0 && root->right == 0){
            if(sum == targetSum){
                ans.push_back(temp);
            }
            else{
                return;
            }
        }
        solve(root->left,targetSum,sum,temp,ans);
        solve(root->right,targetSum,sum,temp,ans);
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        vector<int>temp;
        vector<vector<int>>ans;
        solve(root,targetSum,sum,temp,ans);
        return ans;
    }
};