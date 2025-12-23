class Solution {
public:
    void solve(TreeNode* root, vector<int>arr, vector<vector<int>>& ans){
        if(!root) return;
        queue<TreeNode*>q;
        bool shouldReverse = false;
        
        q.push(root);
        q.push(NULL);

        while(q.size() > 1){
            TreeNode* front = q.front(); q.pop();
            if(!front){
                q.push(NULL);
                if(shouldReverse){
                    reverse(arr.begin(),arr.end());
                }
                ans.push_back(arr);
                arr = {};
                shouldReverse = !shouldReverse;
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
        if(shouldReverse){
             reverse(arr.begin(),arr.end());
        }
        ans.push_back(arr);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<int>arr;
        vector<vector<int>> ans;

        solve(root,arr,ans);
        return ans;
    }
};