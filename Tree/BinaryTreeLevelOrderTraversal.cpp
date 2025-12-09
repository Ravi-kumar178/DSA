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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        vector<int>arr;
        if (!root) return ans;
        queue<TreeNode*>q;

        q.push(root);
        q.push(0);

        while(q.size() >  1){
            TreeNode* front = q.front(); q.pop();
            if(!front){
                ans.push_back(arr);
                arr = {};
                q.push(0);
            }
            else{
                arr.push_back(front->val);
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
        }
        ans.push_back(arr);
        return ans;
    }
};