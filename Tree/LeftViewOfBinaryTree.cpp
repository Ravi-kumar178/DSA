
class Solution {
  public:
  
    void solve(Node* root, int level , vector<int>& ans){
        if(!root) return;
        if(level == ans.size()){
            ans.push_back(root->data);
        }
        //move left and update level
        level += 1;
        solve(root->left,level,ans);
        solve(root->right,level,ans);
    }
  
    vector<int> leftView(Node *root) {
        // code here
        vector<int>ans;
        int level = 0;
        solve(root,level,ans);
        return ans;
    }
};